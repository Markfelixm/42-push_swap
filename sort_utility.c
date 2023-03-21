/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:38:27 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/21 20:33:16 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stacks *stacks)
{
	int	*sorted;
	int	i;

	sorted = bubble_sort_a(stacks);
	i = -1;
	while (++i < stacks->max_len)
	{
		if (sorted[i] != stacks->a[get_index(stacks, stacks->a_start + i)].n)
		{
			free(sorted);
			return (false);
		}
	}
	free(sorted);
	return (true);
}

int	*bubble_sort_a(t_stacks *stacks)
{
	int	*nums;
	int	hold;
	int	i;
	int	j;

	nums = malloc(sizeof(int) * stacks->max_len);
	if (nums == NULL)
		clean_exit(stacks, NULL, true);
	i = stacks->max_len;
	while (--i >= 0)
		nums[i] = stacks->a[i].n;
	while (++i < stacks->max_len)
	{
		j = -1;
		while (++j < stacks->max_len - i - 1)
		{
			if (nums[j] > nums[j + 1])
			{
				hold = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = hold;
			}
		}
	}
	return (nums);
}
