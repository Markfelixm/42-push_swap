/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:05:29 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/14 16:45:33 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op	rra(t_stacks *stacks)
{
	if (stacks->a_len < 2)
		return (RRA);
	stacks->a_start = get_index(stacks, stacks->a_start - 1);
	stacks->a[stacks->a_start] = stacks->a[get_index(stacks, stacks->a_start + stacks->a_len)];
	return (RRA);
}

t_op	rrb(t_stacks *stacks)
{
	if (stacks->b_len < 2)
		return (RRB);
	stacks->b_start = get_index(stacks, stacks->b_start - 1);
	stacks->b[stacks->b_start] = stacks->b[get_index(stacks, stacks->b_start + stacks->b_len)];
	return (RRB);
}

t_op	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
	return (RRR);
}
