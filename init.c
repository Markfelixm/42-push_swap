/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:55:24 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/30 15:56:32 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*init_stacks(int ac)
{
	t_stacks	*stacks;

	stacks = ft_calloc(1, sizeof(t_stacks));
	if (stacks == NULL)
		return (NULL);
	stacks->a = ft_calloc(ac, sizeof(t_elem));
	stacks->b = ft_calloc(ac, sizeof(t_elem));
	if (stacks->a == NULL || stacks->b == NULL)
		clean_exit(stacks, NULL, true);
	stacks->max_len = ac;
	return (stacks);
}

t_ops	*init_ops(int ops_max_len)
{
	t_ops	*ops;
	int		i;

	ops = malloc(sizeof(t_ops));
	if (ops == NULL)
		return (NULL);
	ops->ops = malloc(sizeof(t_op) * ops_max_len);
	if (ops->ops == NULL)
	{
		free (ops);
		return (NULL);
	}
	ops->len = 0;
	i = -1;
	while (++i < ops_max_len)
		ops->ops[i] = NONE;
	return (ops);
}
