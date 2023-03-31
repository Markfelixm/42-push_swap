/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:27:49 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/31 21:15:51 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_order_index_a(t_stacks *stacks, int arg)
{
	int	next;
	int	next_index;
	int	order;
	int	i;

	next_index = INT_MIN;
	next = INT_MAX;
	i = -1;
	while (++i < stacks->a_len)
	{
		order = get(stacks, i, 'a')->order;
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
		return (next_order_index_a(stacks, 0));
	return (next_index);
}

t_ops	*select_best_move(t_stacks *stacks)
{
	t_ops	*best;
	t_ops	*current;
	int		i;
	int		order_index;

	i = -1;
	best = NULL;
	while (++i < stacks->b_len)
	{
		current = init_ops(2 * stacks->max_len);
		if (current == NULL)
			return (free_ops(best));
		index_to_top(stacks, i, 'b', current);
		order_index = next_order_index_a(stacks, get(stacks, i, 'b')->order);
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
	return (best);
}

void	perform_best_move(t_stacks *stacks, t_ops *ops)
{
	t_ops	*best;
	int		i;

	best = select_best_move(stacks);
	if (best == NULL)
	{
		free_ops(best);
		clean_exit(stacks, ops, true);
	}
	i = -1;
	while (++i < best->len)
	{
		do_op(stacks, best->ops[i]);
		add_op(ops, best->ops[i]);
	}
	free_ops(best);
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

t_ops	*mad_sort(t_stacks *stacks)
{
	t_ops	*ops;
	int		order_zero;
	int		op_count;

	ops = init_ops(30 * stacks->max_len);
	if (ops == NULL)
		clean_exit(stacks, NULL, true);
	push_all_but_3(stacks, ops);
	sort_a_of_3(stacks, ops);
	while (stacks->b_len)
		perform_best_move(stacks, ops);
	order_zero = next_order_index_a(stacks, 0);
	op_count = ops->len;
	index_to_top(stacks, order_zero, 'a', ops);
	op_count = ops->len - op_count + 1;
	while (op_count-- > 0)
		do_op(stacks, ops->ops[ops->len - op_count]);
	return (ops);
}
