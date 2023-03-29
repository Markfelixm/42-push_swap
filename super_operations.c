/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:12:45 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/29 19:11:31 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op	smart_rotate(t_stacks *stacks, int i, char stack)
{
	int	len;

	if (stack == 'a')
		len = stacks->a_len;
	else
		len = stacks->b_len;
	if (i <= len / 2)
	{
		if (stack == 'a')
			return (RA);
		return (RB);
	}
	if (stack == 'a')
		return (RRA);
	return (RRB);
}

void	index_to_top(t_stacks *stacks, int i, char stack, t_ops *ops)
{
	int	len;
	int	shortest;

	len = stacks->a_len;
	if (stack == 'b')
		len = stacks->b_len;
	shortest = len - i;
	if (shortest > i)
		shortest = i;
	while (shortest-- > 0)
		add_op(ops, smart_rotate(stacks, i, stack));
}
