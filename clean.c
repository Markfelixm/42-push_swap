/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:27:30 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/29 18:16:43 by marmulle         ###   ########.fr       */
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
		{
			free(ops->ops);
			ops->ops = NULL;
		}
		free(ops);
		ops = NULL;
	}
}

void	free_stacks(t_stacks *stacks)
{
	int	i;

	i = -1;
	if (stacks)
	{
		if (stacks->a)
		{
			while (++i < stacks->a_len)
				if (stacks->a[get_index(stacks, stacks->a_start + i)].moves)
					free_ops(stacks->a[get_index(stacks, stacks->a_start + i)].moves);
			free(stacks->a);
		}
		if (stacks->b)
		{
			i = -1;
			while (++i < stacks->b_len)
				if (stacks->b[get_index(stacks, stacks->b_start + i)].moves)
					free_ops(stacks->b[get_index(stacks, stacks->b_start + i)].moves);
			free(stacks->b);
		}
		free(stacks);
	}
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
