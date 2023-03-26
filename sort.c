/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:27:49 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/26 20:06:06 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ops	*prepare_a_for_pa(t_stacks *stacks)
{
	t_ops	*ops;
	t_ops	*add;
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
	add = index_to_top(stacks, min_delta_index, 'a');
	if (add == NULL)
		clean_exit(stacks, ops, true);
	append_ops(ops, add);
	free_ops(add);
	return(ops);
}
t_ops	*select_best_moves(t_stacks *stacks)
{
	t_ops	*best;
	t_ops	*moves;
	t_ops	*add;
	int		i;

	best = init_ops();
	if (best == NULL)
		return (NULL);
	best->len = INT_MAX;
	i = -1;
	while (++i < stacks->b_len)
	{
		moves = index_to_top(stacks, i, 'b');
		if (moves == NULL)
			return (NULL);
		add = prepare_a_for_pa(stacks);
		append_ops(moves, add);
		free_ops(add);
		add_op(moves, PA);
		if (best->len > moves->len)
			best = moves;
		stacks->b[get_index(stacks, stacks->b_start + i)].moves = moves;
	}
	return (best); // dont free because its already being freed by free_stacks
}

//  TODO: the function that checks if sorted starting at order=0 and rotates it to top if sorted
// the function that pushes everything but 3 to b
// the function that sorts a of len 3
