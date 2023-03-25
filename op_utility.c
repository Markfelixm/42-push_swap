/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:09:44 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/25 19:46:46 by marmulle         ###   ########.fr       */
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
