/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:45:20 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/22 21:45:37 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ops(t_ops	*ops)
{
	int	i;

	i = -1;
	while (++i < ops->len)
		print_op(ops->ops[i]);
}

void	print_op(t_op op)
{
	if (op == 1)
		ft_printf("sa");
	if (op == 2)
		ft_printf("sb");
	if (op == 3)
		ft_printf("ss");
	if (op == 4)
		ft_printf("pa");
	if (op == 5)
		ft_printf("pb");
	if (op == 6)
		ft_printf("ra");
	if (op == 7)
		ft_printf("rb");
	if (op == 8)
		ft_printf("rr");
	if (op == 9)
		ft_printf("rra");
	if (op == 10)
		ft_printf("rrb");
	if (op == 11)
		ft_printf("rrr");
	ft_printf("\n");
}
