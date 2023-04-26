/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:00:17 by marmulle          #+#    #+#             */
/*   Updated: 2023/04/26 19:23:42 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*get(t_stacks *stacks, int i, char stack)
{
	if (stack == 'a')
		return (&stacks->a[get_index(stacks, stacks->a_start + i)]);
	return (&stacks->b[get_index(stacks, stacks->b_start + i)]);
}

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
			return (free_any_and_null(ptr));
		res = res * 10 + (*(str++) - '0');
		if (res * sign < INT_MIN || res * sign > INT_MAX)
			return (free_any_and_null(ptr));
	}
	*ptr = sign * res;
	return (ptr);
}

t_three	get_three(t_stacks *stacks)
{
	t_three	three;

	three.top = stacks->a[get_index(stacks, stacks->a_start)].order;
	three.mid = stacks->a[get_index(stacks, stacks->a_start + 1)].order;
	three.bot = stacks->a[get_index(stacks, stacks->a_start + 2)].order;
	return (three);
}
