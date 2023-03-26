/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:40:20 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/26 18:27:34 by marmulle         ###   ########.fr       */
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

char	**joined_to_splits(char *joined, int *s)
{
	char		**splits;

	splits = ft_split(joined, ' ');
	free(joined);
	if (splits == NULL)
		return (NULL);
	*s = 0;
	while (splits[*s])
		(*s)++;
	if (*s < 2)
		clean_exit(NULL, NULL, false);
	return (splits);
}

t_stacks	*splits_to_stack(char **splits, int *count)
{
	t_stacks	*stacks;
	int			s;
	int			*num_ptr;

	stacks = init_stacks(*count);
	if (stacks == NULL)
		return (NULL);
	s = 0;
	while (s < stacks->max_len)
	{
		num_ptr = atoi_ptr(splits[s]);
		if (num_ptr == NULL)
			return (NULL);
		if (!is_unique(*num_ptr, stacks))
			return (NULL);
		stacks->a_len++;
		stacks->a[s].n = *num_ptr;
		free(num_ptr);
		s++;
	}
	s = 0;
	while (splits[s])
		free(splits[s++]);
	free(splits);
	return (stacks);
}

t_stacks	*parse_to_stacks(int ac, char **av)
{
	t_stacks	*stacks;
	char		*joined;
	char		**splits;
	int			s;

	joined = join_args(ac, av);
	if (joined == NULL)
		return (NULL);
	s = 0;
	splits = joined_to_splits(joined, &s);
	if (splits == NULL)
		return (NULL);
	stacks = splits_to_stack(splits, &s);
	if (stacks == NULL)
		return (NULL);
	return (stacks);
}
