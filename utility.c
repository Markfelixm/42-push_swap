/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:00:17 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/14 13:39:09 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_unique(int num, t_stacks *stacks)
{
	int	index;

	index = 0;
	while (index < stacks->a_len)
		if (stacks->a[index++].n == num)
			return (0);
	index = 0;
	while (index < stacks->b_len)
		if (stacks->b[index++].n == num)
			return (0);
	return (1);
}

int	*atoi_ptr(const char *str)
{
	int		*ptr;
	long	res;
	char	sign;

	ptr = malloc(sizeof(int));
	if (ptr == NULL)
		return (NULL);
	res = 0;
	sign = 1;
	if (*(str) == '-')
			sign = -1;
	if ((*str == '+' || *str == '-') && *(str + 1) != '\0')
		++str;
	while (42)
	{
		if (*str == '\0')
			break ;
		if (!ft_isdigit(*str))
			return (NULL);
		res = res * 10 + (*(str++) - '0');
		if (res < INT_MIN || res > INT_MAX)
			return (NULL);
	}
	*ptr = sign * res;
	return (ptr);
}

t_stacks	*init_stacks(int ac)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		return (NULL);
	stacks->a = malloc(sizeof(t_pair) * ac);
	stacks->b = malloc(sizeof(t_pair) * ac);
	if (stacks->a == NULL || stacks->b == NULL)
	{
		clean_stacks(stacks);
		return (NULL);
	}
	stacks->a_start = 0;
	stacks->b_start = 0;
	stacks->max_len = ac - 1;
	stacks->a_len = stacks->max_len;
	stacks->b_len = 0;
	return (stacks);
}

void	clean_stacks(t_stacks *stacks)
{
	if (stacks == NULL)
		return ;
	if (stacks->a)
		free(stacks->a);
	if (stacks->b)
		free(stacks->b);
	free(stacks);
}

int	get_index(t_stacks *stacks, int i)
{
	if (i < 0)
		return (i + stacks->max_len);
	if (i > stacks->max_len - 1)
		return (i - stacks->max_len);
	return (i);
}
