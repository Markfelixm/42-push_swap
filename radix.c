/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:05:31 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/15 17:49:26 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_stacks *stacks)
{
	t_ops	*ops;
	int		shift;
	int		i;

	ops = init_ops();
	if (ops == NULL)
		return ; // TODO: free and fail gracefully
	shift = -1;
	while (++shift < 4)
	{
		i = -1;
		while (++i < stacks->max_len)
		{
			if (stacks->a[get_index(stacks, stacks->a_start + i)].n & (1 << shift))
				add_op(ops, RA);
			else
				add_op(ops, PB);
		}
		// ft_printf()
		while (i > 0)
		{
			if (ops->ops[ops->len - i] == RA)
				ra(stacks);
			if (ops->ops[ops->len - i] == PB)
				pb(stacks);
			i--;
		}
		while (stacks->b_len)
			add_op(ops, pa(stacks));
		// ft_printf("shift is %d and debug follows\n", shift);
		// debug(stacks);
		// ft_printf("\n\n\n");
	}
}
// ok so if conditions return an operation to add to the list of operations
// then perform that list of ops in a batch before increasing shift

// void	radix(t_stacks *stacks)
// {
// 	int	i;
// 	int	shift;

// 	shift = 0;
// 	while (42)
// 	{
// 		i = -1;
// 		while (++i < stacks->max_len)
// 		{
// 			// ft_printf("expression is %d\n", (((stacks->a[i].n >> shift) & 1) == 1));
// 			if (((stacks->a[get_index(stacks, stacks->a_start + i)].n >> shift) & 1) == 1)
// 			{
// 				// ft_printf("number is %d\n", (stacks->a[i].n));
// 				// ft_printf("bit is %d\n", ((stacks->a[i].n >> shift) & 1));
// 				ra(stacks);
// 			}
// 			else
// 				pb(stacks);
// 		}
// 		i = stacks->b_len;
// 		while (--i >= 0)
// 		{
// 			pa(stacks);
// 		}
// 		if (shift < (int)sizeof(int))
// 		{
// 			ft_printf("shift is %d\n", shift);
// 			shift++;
// 		}
// 		else
// 			break ;
// 	}
// }

// void	set_order(t_stacks *stacks)
// {
// 	int	num;
// 	int	i;

// 	num = find_min(stacks);
// 	i = stacks->max_len;
// 	while (--i >= 0)
// 	{

// 	}
// }

int	find_min(t_stacks *stacks)
{
	int	min;
	int	i;

	min = INT_MAX;
	i = -1;
	while (++i < stacks->max_len)
		if (min > stacks->a[i].n)
			min = stacks->a[i].n;
	return (min);
}
