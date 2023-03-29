/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:27:49 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/29 21:00:44 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_order_index(t_stacks *stacks, int arg, char stack)
{
	int	next;
	int	next_index;
	int	len;
	int	order;
	int	i;

	next_index = INT_MIN;
	len = stacks->a_len;
	if (stack == 'b')
		len = stacks->b_len;
	next = INT_MAX;
	i = -1;
	while (++i < len)
	{
		order = get(stacks, i, 'a')->order;
		if (stack == 'b')
			order = get(stacks, i, 'b')->order;
		if (order >= arg)
		{
			if (next > order)
			{
				next = order;
				next_index = i;
			}
		}
	}
	if (next == INT_MAX)
		return (next_order_index(stacks, 0, stack));
	return (next_index);
}

void	select_best_moves(t_stacks *stacks, t_ops *ops)
{
	t_ops	*best;
	t_ops	*current;
	int		i;
	int		order_index;

	i = -1;
	best = NULL;
	while (++i < stacks->b_len)
	{
		current = init_ops();
		if (current == NULL)
		{
			free_ops(best);
			clean_exit(stacks, ops, true);
		}
		index_to_top(stacks, i, 'b', current);
		order_index = next_order_index(stacks, get(stacks, i, 'b')->order, 'a');
		index_to_top(stacks, order_index, 'a', current);
		add_op(current, PA);
		if (best == NULL || best->len > current->len)
		{
			free_ops(best);
			best = current;
		}
		else
			free_ops(current);
	}
	i = -1;
	while (++i < best->len)
	{
		do_op(stacks, best->ops[i]);
		add_op(ops, best->ops[i]);
	}
	free_ops(best);
}

t_ops	*mad_sort(t_stacks *stacks)
{
	t_ops	*ops;
	int		order_zero;
	int		op_count;

	ops = init_ops();
	if (ops == NULL)
		clean_exit(stacks, NULL, true);
	push_all_but_3(stacks, ops);
	sort_a_of_3(stacks, ops);
	while (stacks->b_len)
		select_best_moves(stacks, ops);
	order_zero = next_order_index(stacks, 0, 'a');
	op_count = ops->len;
	index_to_top(stacks, order_zero, 'a', ops);
	op_count = ops->len - op_count + 1;
	while (op_count-- > 0)
		do_op(stacks, ops->ops[ops->len - op_count]);
	return (ops);
}

void	push_all_but_3(t_stacks *stacks, t_ops *ops)
{
	while (stacks->a_len > 3)
		add_op(ops, pb(stacks));
}

t_three	get_three(t_stacks *stacks)
{
	t_three	three;

	three.top = stacks->a[get_index(stacks, stacks->a_start)].order;
	three.mid = stacks->a[get_index(stacks, stacks->a_start + 1)].order;
	three.bot = stacks->a[get_index(stacks, stacks->a_start + 2)].order;
	return (three);
}

void	sort_a_of_3(t_stacks *stacks, t_ops *ops)
{
	t_three	three;

	three = get_three(stacks);
	if (three.mid > three.top)
	{
		if (three.bot > three.mid)
			return ;
		if (three.bot > three.top)
			add_op(ops, sa(stacks));
		else
		{
			add_op(ops, rra(stacks));
			return ;
		}
	}
	three = get_three(stacks);
	if (three.bot > three.top)
	{
		add_op(ops, sa(stacks));
		return ;
	}
	add_op(ops, ra(stacks));
	if (three.mid > three.bot)
		add_op(ops, sa(stacks));
}
