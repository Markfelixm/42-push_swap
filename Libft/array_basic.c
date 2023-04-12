/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:16:37 by marmulle          #+#    #+#             */
/*   Updated: 2023/04/07 17:50:51 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	arr_set(t_arr *arr, int i, void *el)
{
	if (i < arr->max_len)
		arr->data[i] = el;
}

void	*arr_get(t_arr *arr, int i)
{
	if (i < arr->len)
		return (arr->data[i]);
	return (NULL);
}

void	arr_del(t_arr *arr, int i)
{
	if (arr->free_el)
		arr->free_el(arr->data[i]);
	i--;
	while (++i < arr->len - 1)
		arr->data[i] = arr->data[i + 1];
	arr->data[i] = NULL;
	arr->len--;
}

void	arr_insert(t_arr *arr, int i, void *el)
{
	int	j;

	if (arr->len + 1 > arr->max_len)
		return ;
	j = arr->len;
	while (--j >= i)
		arr->data[j + 1] = arr->data[j];
	arr->data[i] = el;
	arr->len++;
}

void	arr_print(t_arr *arr)
{
	int	i;

	i = -1;
	if (arr->print_el)
	{
		while (++i < arr->len)
			arr->print_el(arr_get(arr, i));
	}
}
