/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:13:19 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/14 14:01:23 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op	sa(t_stacks *stacks)
{
	t_pair	hold;

	if (stacks->a_len < 2)
		return (SA);
	hold = stacks->a[stacks->a_start];
	stacks->a[stacks->a_start] = stacks->a[get_index(stacks, stacks->a_start + 1)];
	stacks->a[get_index(stacks, stacks->a_start + 1)] = hold;
	return (SA);
}

t_op	sb(t_stacks *stacks)
{
	t_pair	hold;

	if (stacks->b_len < 2)
		return (SB);
	hold = stacks->b[stacks->b_start];
	stacks->b[stacks->b_start] = stacks->b[get_index(stacks, stacks->b_start + 1)];
	stacks->b[get_index(stacks, stacks->b_start + 1)] = hold;
	return (SB);
}

t_op	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
	return (SS);
}
