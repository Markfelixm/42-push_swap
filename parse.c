/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:40:20 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/21 14:42:11 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_args(int ac, char **av)
{
	char	*padded;
	char	*hold;
	char	*joined;
	int		a;

	a = 0;
	joined = NULL;
	while (++a < ac)
	{
		padded = ft_strjoin(av[a], " ");
		hold = ft_strjoin(joined, padded);
		if (padded)
			free(padded);
		if (joined)
			free(joined);
		joined = ft_strdup(hold);
		if (hold)
			free(hold);
	}
	return (joined);
}

t_stacks	*joined_to_stacks(char *joined)
{
	t_stacks	*stacks;
	char		**splits;;
	int			s;
	int			*num_ptr;

	splits = ft_split(joined, ' ');
	if (splits == NULL)
		return (NULL);
	s = 0;
	while (splits[s])
		s++;
	if (s < 2)
		return (NULL);
	stacks = init_stacks(s);
	if (stacks == NULL)
		return (NULL);
	s = 0;
	while (s < stacks->a_len)
	{
		num_ptr = atoi_ptr(splits[s]);
		if (num_ptr == NULL)
			return (NULL);
		if (!is_unique(*num_ptr, stacks))
			return (NULL);
		stacks->a[s].n = *num_ptr;
		free (num_ptr);
		s++;
	}
	return (stacks);
}

t_stacks	*parse_to_stacks(int ac, char **av)
{
	char		*joined;
	t_stacks	*stacks;

	joined = join_args(ac, av);
	if (joined == NULL)
		return (NULL);
	stacks = joined_to_stacks(joined);
	if (stacks == NULL)
		return (NULL);
	return (stacks);
}
