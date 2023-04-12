/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:44:10 by marmulle          #+#    #+#             */
/*   Updated: 2023/04/12 17:52:59 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	plusplus(int *a, int *b, int *i)
{
	if (a)
		(*a)++;
	if (b)
		(*b)++;
	if (i)
		(*i)++;
}

void	optimize_rotates(t_ops *ops)
{
	t_op	op;
	int		b;
	int		a;
	int		i;

	i = -1;
	while (++i < ops->len)
	{
		b = 0;
		a = 0;
		op = seek_to_rotate(ops, &i);
		while (ops->ops[i] == op)
			plusplus(NULL, &b, &i);
		while (ops->ops[i] == op - 1 && a < b)
			plusplus(&a, NULL, &i);
		if (b > a)
			b = a;
		while (b > 0)
			ops->ops[i - b-- - a] = op + 1;
		while (a > 0)
			ops->ops[i - a--] = NONE;
	}
}

t_op	seek_to_rotate(t_ops *ops, int *i)
{
	while (*i < ops->len - 1
		&& ops->ops[*i] != RB && ops->ops[*i] != RRB)
		(*i)++;
	if (*i == ops->len - 1)
		return (NONE);
	return (ops->ops[*i]);
}

bool	half_stack_average_is_high(t_stacks *stacks)
{
	int	half_sum;
	int	sum;
	int	i;

	i = -1;
	half_sum = 0;
	sum = 0;
	while (i < stacks->a_len)
	{
		if (i < stacks->a_len / 2)
			half_sum += get(stacks, i, 'a')->order;
		sum += get(stacks, i++, 'a')->order;
	}
	if (half_sum < sum / 2)
		return (false);
	return (true);
}

void	rough_sort_push(t_stacks *stacks, t_ops *ops)
{
	bool	half_is_high;

	half_is_high = half_stack_average_is_high(stacks);
	while (stacks->a_len > 3)
	{
		add_op(ops, pb(stacks));
		if (stacks->b_len > 1)
		{
			if (half_is_high)
			{
				if (get(stacks, 0, 'b')->order > stacks->max_len / 2)
					add_op(ops, rb(stacks));
			}
			else
			{
				if (get(stacks, 0, 'b')->order < stacks->max_len / 2)
					add_op(ops, rb(stacks));
			}
		}
	}
}
