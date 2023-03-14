/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:13:22 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/14 13:52:23 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op	pa(t_stacks *stacks)
{
	if (stacks->b_len == 0)
		return (PA);
	stacks->a_start = get_index(stacks, stacks->a_start - 1);
	stacks->a[stacks->a_start] = stacks->b[stacks->b_start];
	stacks->a_len++;
	stacks->b_len--;
	stacks->b_start = get_index(stacks, stacks->b_start + 1);
	return (PA);
}

t_op	pb(t_stacks *stacks)
{
	if (stacks->a_len == 0)
		return (PB);
	stacks->b_start = get_index(stacks, stacks->b_start - 1);
	stacks->b[stacks->b_start] = stacks->a[stacks->a_start];
	stacks->b_len += 1;
	stacks->a_len -= 1;
	stacks->a_start = get_index(stacks, stacks->a_start + 1);
	return (PB);
}
