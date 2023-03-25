/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:27:49 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/25 20:24:23 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ops	*prepare_a_for_pa(t_stacks *stacks)
{
	t_ops	*ops;
	t_ops	*ops_to_add;
	int		min_delta;
	int		min_delta_index;
	int		i;

	ops = init_ops();
	if (ops == NULL)
		return (NULL);
	min_delta = INT_MAX;
	min_delta_index = 0;
	i = -1;
	while (++i < stacks->a_len)
	{
		if (stacks->a[get_index(stacks, stacks->a_start + i)].order > stacks->b[get_index(stacks, stacks->b_start)].order)
			if (min_delta > stacks->a[get_index(stacks, stacks->a_start + i)].order - stacks->b[stacks->b_start].order)
			{
				min_delta = stacks->a[get_index(stacks, stacks->a_start + i)].order - stacks->b[stacks->b_start].order;
				min_delta_index = i;
			}
	}
	ops_to_add = index_to_top(stacks, min_delta_index, 'a');
	append_ops(ops, ops_to_add);
	free(ops_to_add);
	return(ops);
}
 // TODO: now make a function that checks if sorted regardless or end/start points. then its just an matter or rotating to return the stack a sorted
