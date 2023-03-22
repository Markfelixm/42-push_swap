/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:09:44 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/22 22:25:22 by marmulle         ###   ########.fr       */
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

// void	shift_ops(t_stacks *stacks, t_ops *ops, int from, int to)
// {
// 	// this wont shift towards end because im looking for NONE. need a count but then cant pass stacks to clean exit..
// 	t_ops	*copy;
// 	int		count;
// 	int		i;

// 	copy = init_ops();
// 	if (copy == NULL)
// 		clean_exit(stacks, ops, true);
// 	count = -1;
// 	while (++count < OPS_MAX_LEN - from)
// 		if (ops->ops[from + count] == NONE)
// 			break ;
// 	i = -1;
// 	while (++i < count)
// 	{
// 		copy->ops[i] = ops->ops[from + i];
// 		ops->ops[from + i] = NONE;
// 	}
// 	i = -1;
// 	while (++i < count)

// }

// void	insert_ops_at_index(t_ops *ops, t_op op, int i)
// {

// }
