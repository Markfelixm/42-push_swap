/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:09:44 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/26 17:07:03 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ops	*init_ops(void)
{
	t_ops	*ops;
	int		i;

	ops = malloc(sizeof(t_ops));
	if (ops == NULL)
		return (NULL);
	ops->ops = malloc(sizeof(t_op) * OPS_MAX_LEN);
	if (ops->ops == NULL)
	{
		free (ops);
		return (NULL);
	}
	ops->len = 0;
	i = -1;
	while (++i < OPS_MAX_LEN)
		ops->ops[i] = NONE;
	return (ops);
}

void	add_op(t_ops *ops, t_op op)
{
	ops->ops[ops->len++] = op;
}

void	append_ops(t_ops *target, t_ops *add)
{
	int	offset;
	int	cursor;

	if (add == NULL)
		return ;
	offset = target->len;
	cursor = -1;
	while (++cursor < offset + add->len)
		target->ops[offset + cursor] = add->ops[cursor];
	target->len += add->len;
}

void	perform_ops(t_stacks *stacks, t_ops *ops)
{
	int	i;

	i = -1;
	while (++i < ops->len)
		do_op(stacks, ops->ops[i]);
}

void	do_op(t_stacks *stacks, t_op op)
{
	if (op == 1)
		sa(stacks);
	if (op == 2)
		sb(stacks);
	if (op == 3)
		ss(stacks);
	if (op == 4)
		pa(stacks);
	if (op == 5)
		pb(stacks);
	if (op == 6)
		ra(stacks);
	if (op == 7)
		rb(stacks);
	if (op == 8)
		rr(stacks);
	if (op == 9)
		rra(stacks);
	if (op == 10)
		rrb(stacks);
	if (op == 11)
		rrr(stacks);
}
