/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:00:17 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/29 14:49:23 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stacks *stacks, int i)
{
	if (i < 0)
		return (i + stacks->max_len);
	if (i > stacks->max_len - 1)
		return (i - stacks->max_len);
	return (i);
}

bool	is_unique(int num, t_stacks *stacks)
{
	int	index;

	index = 0;
	while (index < stacks->a_len)
		if (stacks->a[index++].n == num)
			return (false);
	index = 0;
	while (index < stacks->b_len)
		if (stacks->b[index++].n == num)
			return (false);
	return (true);
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
