/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:44:10 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/31 21:30:25 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	replace_double_ops(t_ops *ops, t_op op)
void	optimize_rr(t_ops *ops)
{
	t_op	op;
	int		b;
	int		a;
	int		i;

	i = -1;
	while (++i < ops->len)
	{
		b = 0;
		a = 0;
		op = seek_to_rotate(ops, &i);
		while (ops->ops[i] == op)
		{
			i++;
			b++;
		}
		while (ops->ops[i] == op - 1 && a < b)
		{
			i++;
			a++;
		}
		if (b > a)
			b = a;
		while (b > 0)
			ops->ops[i - b-- - a] = op + 1;
		while (a > 0)
			ops->ops[i - a--] = NONE;
	}
}

t_op	seek_to_rotate(t_ops *ops, int *i)
{
	while (*i < ops->len - 1
		&& ops->ops[*i] != RB && ops->ops[*i] != RRB)
		(*i)++;
	if (*i == ops->len - 1)
		return (NONE);
	return (ops->ops[*i]);
}

// void	seek_to_op(t_ops *ops, t_op op, int *i)
// {
// 	while (*i < ops->len && ops->ops[*i] != op)
// 		(*i)++;
// }
