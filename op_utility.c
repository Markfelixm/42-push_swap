/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:09:44 by marmulle          #+#    #+#             */
/*   Updated: 2023/04/15 15:10:11 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_op(t_ops *ops, t_op op)
{
	ops->ops[ops->len++] = op;
}

void	do_op(t_stacks *stacks, t_op op)
{
	if (op == SA)
		sa(stacks);
	else if (op == SB)
		sb(stacks);
	else if (op == SS)
		ss(stacks);
	else if (op == PA)
		pa(stacks);
	else if (op == PB)
		pb(stacks);
	else if (op == RA)
		ra(stacks);
	else if (op == RB)
		rb(stacks);
	else if (op == RR)
		rr(stacks);
	else if (op == RRA)
		rra(stacks);
	else if (op == RRB)
		rrb(stacks);
	else if (op == RRR)
		rrr(stacks);
}

void	perform_ops(t_stacks *stacks, t_ops	*ops)
{
	int	i;

	if (ops == NULL)
		return ;
	i = -1;
	while (++i < ops->len)
		do_op(stacks, ops->ops[i]);
}
