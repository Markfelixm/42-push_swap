/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_convenience.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:16:34 by marmulle          #+#    #+#             */
/*   Updated: 2023/04/07 15:17:49 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	arr_append(t_arr *arr, void *el)
{
	if (arr->len + 1 > arr->max_len)
		return ;
	arr->data[arr->len] = el;
	arr->len++;
}

void	arr_prepend(t_arr *arr, void *el)
{
	arr_insert(arr, 0, el);
	arr->len++;
}
