/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:13:22 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/21 20:33:42 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op	ra(t_stacks *stacks)
{
	if (stacks->a_len < 2)
		return (RA);
	stacks->a[get_index(stacks,
			stacks->a_start + stacks->a_len)] = stacks->a[stacks->a_start];
	stacks->a_start = get_index(stacks, stacks->a_start + 1);
	return (RA);
}

t_op	rb(t_stacks *stacks)
{
	if (stacks->b_len < 2)
		return (RB);
	stacks->b[get_index(stacks,
			stacks->b_start + stacks->b_len)] = stacks->b[stacks->b_start];
	stacks->b_start = get_index(stacks, stacks->b_start + 1);
	return (RB);
}

t_op	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
	return (RR);
}
