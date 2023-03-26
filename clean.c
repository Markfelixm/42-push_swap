/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:27:30 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/26 19:37:15 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_exit(t_stacks *stacks, t_ops *ops, bool is_error)
{
	free_ops(ops);
	free_stacks(stacks);
	if (is_error)
		write(2, "Error\n", 6);
	exit((int)is_error);
}

void	free_ops(t_ops *ops)
{
	if (ops)
	{
		if (ops->ops)
			free(ops->ops);
		free(ops);
	}
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->a)
		{
			while (--(stacks->a_len) >= 0)
				free_ops(stacks->a[stacks->a_len].moves);
			free(stacks->a);
		}
		if (stacks->b)
		{
			while (--(stacks->b_len) >= 0)
				free_ops(stacks->b[stacks->b_len].moves);
			free(stacks->b);
		}
		free(stacks);
	}
}
