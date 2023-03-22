/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:44:47 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/22 20:02:30 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug(t_stacks *stacks)
{
	int index;

	ft_printf("==============================START===========================\n");
	ft_printf("A\n");
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
	ft_printf("start:\t%d\n", stacks->a_start);


	ft_printf("\nB\n");
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
	ft_printf("start:\t%d\n", stacks->b_start);
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
	ops = radix(stacks);
	if (ops != NULL)
		print_ops(ops);
	// debug(stacks); // TODO: remove debugging
	// leaks -q --atExit -- ./push_swap $(cat 100.txt)
	clean_exit(stacks, ops, false);
}
