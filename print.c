/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:45:20 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/30 20:12:35 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ops(t_ops	*ops)
{
	int	i;

	if (ops == NULL)
		return ;
	i = -1;
	while (++i < ops->len)
		print_op(ops->ops[i]);
}

void	print_op(t_op op)
{
	if (op == SA)
		ft_printf("sa");
	else if (op == SB)
		ft_printf("sb");
	else if (op == SS)
		ft_printf("ss");
	else if (op == PA)
		ft_printf("pa");
	else if (op == PB)
		ft_printf("pb");
	else if (op == RA)
		ft_printf("ra");
	else if (op == RB)
		ft_printf("rb");
	else if (op == RR)
		ft_printf("rr");
	else if (op == RRA)
		ft_printf("rra");
	else if (op == RRB)
		ft_printf("rrb");
	else if (op == RRR)
		ft_printf("rrr");
	ft_printf("\n");
}
