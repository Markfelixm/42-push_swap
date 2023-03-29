/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:27:49 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/29 18:34:39 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_order(t_stacks *stacks, int arg, char stack)
{
	int	next;
	int	next_index;
	int	len;
	int	order;
	int	i;

	next_index = INT_MIN;
	stack = ft_tolower(stack);
	if (stack != 'a' && stack != 'b')
		return (next_index);
	len = stacks->a_len;
	if (stack == 'b')
		len = stacks->b_len;
	next = INT_MAX;
	i = -1;
	while (++i < len)
	{
		order = stacks->a[get_index(stacks, stacks->a_start + i)].order;
		if (stack == 'b')
			order = stacks->b[get_index(stacks, stacks->b_start + i)].order;
		if (order >= arg)
			if (next > order)
			{
				next = order;
				next_index = i;
			}
	}
	if (next == INT_MAX)
		return (find_next_order(stacks, 0, stack));
	return (next_index);
}

t_ops	*select_best_moves(t_stacks *stacks)
{
	t_ops	*best;
	t_ops	*moves;
	t_ops	*add;
	int		i;
	int		next_order_index;

	best = init_ops();
	if (best == NULL)
		return (NULL);
	best->len = INT_MAX;
	i = -1;
	while (++i < stacks->b_len)
	{
		moves = index_to_top(stacks, i, 'b');
		if (moves == NULL)
		{
			clean_exit(stacks, best, true);
		}
			// return (NULL);
		next_order_index = find_next_order(stacks, stacks->b[get_index(stacks, stacks->b_start + i)].order, 'a');
		add = index_to_top(stacks, next_order_index, 'a');
		// add = prepare_a_for_pa(stacks);
		append_ops(moves, add);
		free_ops(add);
		add_op(moves, PA);
		if (best->len > moves->len)
		{
			free_ops(best);
			best = moves;
		}
		// stacks->b[get_index(stacks, stacks->b_start + i)].moves = moves;
	}
	if (best->len == INT_MAX)
		best->len = 0;
	return (best);
}

t_ops	*mad_sort(t_stacks *stacks)
{
	t_ops	*ops;
	t_ops	*add;

	ops = push_all_but_3(stacks); // performs
	add = sort_a_of_3(stacks); // performs
	append_ops(ops, add);
	free_ops(add);
	add = select_best_moves(stacks);
	perform_ops(stacks, add);
	append_ops(ops, add);
	free_ops(add);
	return (ops);
}

t_ops	*push_all_but_3(t_stacks *stacks)
{
	t_ops	*ops;
	int	i;

	ops = init_ops();
	if (ops == NULL)
		clean_exit(stacks, NULL, true);
	i = -1;
	while (stacks->a_len > 3)
		add_op(ops, pb(stacks));
	return (ops);
}

t_three	get_three(t_stacks *stacks)
{
	t_three	three;

	three.top = stacks->a[get_index(stacks, stacks->a_start)].order;
	three.mid = stacks->a[get_index(stacks, stacks->a_start + 1)].order;
	three.bot = stacks->a[get_index(stacks, stacks->a_start + 2)].order;
	return (three);
}

t_ops	*sort_a_of_3(t_stacks *stacks)
{
	t_ops	*ops;
	t_three	three;

	ops = init_ops();
	if (ops == NULL)
		clean_exit(stacks, NULL, true);
	three = get_three(stacks);
	if (three.mid > three.top)
	{
		if (three.bot > three.mid)
			return (ops);
		if (three.bot > three.top)
			add_op(ops, sa(stacks));
		else
		{
			add_op(ops, rra(stacks));
			return (ops);
		}
	}
	three = get_three(stacks);
	if (three.bot > three.top)
	{
		add_op(ops, sa(stacks));
		return (ops);
	}
	add_op(ops, ra(stacks));
	if (three.mid > three.bot)
		add_op(ops, sa(stacks));
	return (ops);
}

//  TODO: the function that checks if sorted starting at order=0 and rotates it to top if sorted
// the function that sorts a of len 3
// (optional) longest consecutive sorted sequence
