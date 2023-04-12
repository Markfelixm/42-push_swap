/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:04:59 by marmulle          #+#    #+#             */
/*   Updated: 2023/04/07 17:17:40 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static void	arr_link_fn(t_arr *arr, t_free_el free_el, t_print_el print_el)
{
	arr->free_el = free_el;
	arr->print_el = print_el;
	arr->set = arr_set;
	arr->get = arr_get;
	arr->del = arr_del;
	arr->insert = arr_insert;
	arr->append = arr_append;
	arr->prepend = arr_prepend;
	arr->print = arr_print;
}

t_arr	*arr_init(
			int max_len, int el_size, t_free_el free_el, t_print_el print_el)
{
	t_arr	*arr;

	arr = malloc(sizeof(t_arr));
	if (arr == NULL)
		return (NULL);
	arr->data = ft_calloc(max_len, el_size);
	if (arr->data == NULL)
	{
		free (arr);
		return (NULL);
	}
	arr->max_len = max_len;
	arr->len = 0;
	arr_link_fn(arr, free_el, print_el);
	return (arr);
}

void	arr_clear(t_arr *arr)
{
	int	i;

	if (arr)
	{
		if (arr->data)
		{
			if (arr->free_el)
			{
				i = -1;
				while (++i < arr->len)
					arr->free_el(arr->data[i]);
			}
			free(arr->data);
			arr->data = NULL;
		}
		free(arr);
		arr = NULL;
	}
}

t_arr	*arr_resize(t_arr *arr, int max_len, int el_size)
{
	t_arr	*new;
	int		i;

	if (arr == NULL)
		return (NULL);
	new = arr_init(max_len, el_size, arr->free_el, arr->print_el);
	if (new == NULL)
		return (NULL);
	i = -1;
	while (++i < arr->len)
		arr_append(new, arr_get(arr, i));
	arr_clear(arr);
	return (new);
}
