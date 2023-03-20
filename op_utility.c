/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:09:44 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/20 21:20:03 by marmulle         ###   ########.fr       */
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
	{
		if (ops->ops[i] == 0)
			ft_printf("sa");
		if (ops->ops[i] == 1)
			ft_printf("sb");
		if (ops->ops[i] == 2)
			ft_printf("ss");
		if (ops->ops[i] == 3)
			ft_printf("pa");
		if (ops->ops[i] == 4)
			ft_printf("pb");
		if (ops->ops[i] == 5)
			ft_printf("ra");
		if (ops->ops[i] == 6)
			ft_printf("rb");
		if (ops->ops[i] == 7)
			ft_printf("rr");
		if (ops->ops[i] == 8)
			ft_printf("rra");
		if (ops->ops[i] == 9)
			ft_printf("rrb");
		if (ops->ops[i] == 10)
			ft_printf("rrr");
		ft_printf("\n");
	}
}

// void	perform_ops(t_ops *ops, t_stacks *stacks, int start)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < ops->len)
// 	{
// 		if (ops->ops[i] == 0)
// 			sa(stacks);
// 		if (ops->ops[i] == 1)
// 			sb(stacks);
// 		if (ops->ops[i] == 2)
// 			ss(stacks);
// 		if (ops->ops[i] == 3)
// 			pa(stacks);
// 		if (ops->ops[i] == 4)
// 			pb(stacks);
// 		if (ops->ops[i] == 5)
// 			ra(stacks);
// 		if (ops->ops[i] == 6)
// 			rb(stacks);
// 		if (ops->ops[i] == 7)
// 			rr(stacks);
// 		if (ops->ops[i] == 8)
// 			rra(stacks);
// 		if (ops->ops[i] == 9)
// 			rrb(stacks);
// 		if (ops->ops[i] == 10)
// 			rrr(stacks);
// 	}
// }
