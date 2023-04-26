/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:27:30 by marmulle          #+#    #+#             */
/*   Updated: 2023/04/26 19:18:07 by marmulle         ###   ########.fr       */
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

void	free_stacks(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->a)
			free(stacks->a);
		if (stacks->b)
			free(stacks->b);
		free(stacks);
	}
}

void	*free_ops(t_ops *ops)
{
	if (ops)
	{
		if (ops->ops)
			free(ops->ops);
		free(ops);
	}
	return (NULL);
}

void	*free_splits(char **splits)
{
	size_t	s;

	s = 0;
	if (splits)
	{
		while (splits[s])
			free(splits[s++]);
		free(splits);
	}
	return (NULL);
}

void	*free_any_and_null(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}
