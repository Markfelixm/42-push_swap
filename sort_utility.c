/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:38:27 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/22 18:09:55 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stacks *stacks)
{
	int	num;
	int	i;

	num = INT_MIN;
	i = stacks->b_len;
	while (--i >= 0)
	{
		if (num >= stacks->b[get_index(stacks, stacks->b_start + i)].order)
			return (false);
		num = stacks->b[get_index(stacks, stacks->b_start + i)].order;
	}
	while (++i < stacks->a_len)
	{
		if (num >= stacks->a[get_index(stacks, stacks->a_start + i)].order)
			return (false);
		num = stacks->a[get_index(stacks, stacks->a_start + i)].order;
	}
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
