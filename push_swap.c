/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:44:47 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/26 19:58:20 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug(t_stacks *stacks)
{
	int index;

	ft_printf("==============================START===========================\n");
	ft_printf("A\t");
	index = 0;
	while (index < stacks->a_len)
	{
		ft_printf("%d ", stacks->a[get_index(stacks, stacks->a_start + index)].n);
		index++;
	}
	// ft_printf("\nactual:\t[ ");
	// index = 0;
	// while (index < stacks->max_len)
	// {
	// 	ft_printf("%d ", stacks->a[index].n);
	// 	index++;
	// }
	// ft_printf("]");
	ft_printf("\nlen:\t%d\n", stacks->a_len);
	// ft_printf("start:\t%d\n", stacks->a_start);


	ft_printf("\nB\t");
	index = 0;
	while (index < stacks->b_len)
	{
		ft_printf("%d ", stacks->b[get_index(stacks, stacks->b_start + index)].n);
		index++;
	}
	// ft_printf("\nactual:\t[ ");
	// index = 0;
	// while (index < stacks->max_len)
	// {
	// 	ft_printf("%d ", stacks->b[index].n);
	// 	index++;
	// }
	// ft_printf("]");
	ft_printf("\nlen:\t%d\n", stacks->b_len);
	// ft_printf("start:\t%d\n", stacks->b_start);
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	t_ops		*ops;

	if (ac < 2)
		return (42);
	stacks = parse_to_stacks(ac, av);
	if (stacks == NULL)
		clean_exit(stacks, NULL, true);
	if (is_sorted(stacks))
		clean_exit(stacks, NULL, false);
	set_order(stacks);
	// debug

	pb(stacks);
	pb(stacks);
	pb(stacks);
	ft_printf("===========================iterations start==========================\n");
	while (stacks->b_len)
	{
		debug(stacks);
		ft_printf("operations to perform:\n");
		ops = select_best_moves(stacks);
		print_ops(ops);
		perform_ops(stacks, ops);
	}

	debug(stacks);
	// end debug
	clean_exit(stacks, NULL, false);
}
