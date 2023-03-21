/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:09:44 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/21 17:30:53 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ops	*init_ops(void)
{
	t_ops	*ops;

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
	ops->marker = 0;
	return (ops);
}

void	add_op(t_ops *t_ops, t_op op)
{
	t_ops->ops[t_ops->len++] = op;
}

void	print_ops(t_ops	*ops)
{
	int	i;

	i = -1;
	while (++i < ops->len)
		print_op(ops->ops[i]);
}

void	print_op(t_op op)
{
	if (op == 0)
		ft_printf("sa");
	if (op == 1)
		ft_printf("sb");
	if (op == 2)
		ft_printf("ss");
	if (op == 3)
		ft_printf("pa");
	if (op == 4)
		ft_printf("pb");
	if (op == 5)
		ft_printf("ra");
	if (op == 6)
		ft_printf("rb");
	if (op == 7)
		ft_printf("rr");
	if (op == 8)
		ft_printf("rra");
	if (op == 9)
		ft_printf("rrb");
	if (op == 10)
		ft_printf("rrr");
	ft_printf("\n");
}
