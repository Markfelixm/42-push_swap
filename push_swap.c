/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:44:47 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/20 21:46:32 by marmulle         ###   ########.fr       */
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
	t_ops	*ops;
	t_stacks *stacks;
	int		*num_ptr;
	int		index;

	if (ac < 3)
		return (42);
	stacks = init_stacks(ac);
	if (stacks == NULL)
		return (write(2, "Error\n", 6));
	index = 0;
	while (index < stacks->a_len)
	{
		num_ptr = atoi_ptr(av[index + 1]);
		if (num_ptr == NULL)
			return (write(2, "Error\n", 6));
		if (!is_unique(*num_ptr, stacks))
			return (write(2, "Error\n", 6));
		stacks->a[index].n = *num_ptr;
		free (num_ptr);
		index++;
	}
	// TODO: handle input as a string aswell, i.e. if ac == 2

	// debug
	ops = radix(stacks);
	if (ops != NULL)
		print_ops(ops);
	// end debug

	// TODO: free everything
	clean_exit(stacks, ops, false);
}
