/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:05:31 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/25 20:03:53 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ops	*radix(t_stacks *stacks)
{
	t_ops	*ops;
	int		shift;
	int		i;

	ops = init_ops();
	if (ops == NULL)
		return (NULL);
	shift = -1;
	while (++shift < (int) sizeof(int) * 8)
	{
		i = -1;
		while (++i < stacks->a_len)
		{
			if (stacks->a[get_index(stacks, stacks->a_start + i)].order & (1 << shift))
				add_op(ops, RA);
			else
				add_op(ops, PB);
		}
		while (--i >= 0)
		{
			if (ops->ops[ops->len - i - 1] == PB)
				pb(stacks);
			if (ops->ops[ops->len - i - 1] == RA)
				ra(stacks);
		}
		if (is_sorted(stacks))
		{
			while (stacks->b_len)
				add_op(ops, pa(stacks));
			return (ops);
		}
		while (++i < stacks->b_len)
		{
			if (stacks->b[get_index(stacks, stacks->b_start + i)].order & (1 << (shift + 1)))
				add_op(ops, PA);
			else
				add_op(ops, RB);
		}
		while (--i >= 0)
		{
			if (ops->ops[ops->len - i - 1] == PA)
				pa(stacks);
			if (ops->ops[ops->len - i - 1] == RB)
				rb(stacks);
		}
	}
	return (ops);
}

void	set_order(t_stacks *stacks)
{
	int	*copy;
	int	i;
	int	j;

	copy = bubble_sort_a(stacks);
	if (copy == NULL)
		clean_exit(stacks, NULL, true); // TODO: need to free ops first
	i = -1;
	while (++i < stacks->max_len)
	{
		j = -1;
		while (++j < stacks->max_len)
		{
			if (copy[i] == stacks->a[get_index(stacks, j)].n)
			{
				stacks->a[get_index(stacks, j)].order = i;
				break ;
			}
		}
	}
	free(copy);
}
