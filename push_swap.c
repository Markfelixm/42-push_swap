/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:44:47 by marmulle          #+#    #+#             */
/*   Updated: 2023/04/12 17:53:43 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	t_ops		*ops;

	if (ac < 2)
		return (42);
	stacks = parse_to_stacks(ac, av);
	if (stacks == NULL)
		clean_exit(stacks, NULL, true);
	set_order(stacks);
	if (is_sorted(stacks))
		clean_exit(stacks, NULL, false);
	ops = mad_sort(stacks);
	optimize_rotates(ops);
	print_ops(ops);
	clean_exit(stacks, ops, false);
}
