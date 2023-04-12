/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:59:40 by marmulle          #+#    #+#             */
/*   Updated: 2023/04/07 17:17:29 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include "libft.h"

typedef void	(*t_free_el)(void *);
typedef void	(*t_print_el)(void *);

typedef struct s_arr
{
	void		***data;
	int			len;
	int			max_len;
	t_free_el	free_el;
	t_print_el	print_el;
	void		(*set)(struct s_arr *, int, void *);
	void		*(*get)(struct s_arr *, int);
	void		(*del)(struct s_arr *, int);
	void		(*insert)(struct s_arr *, int, void *);
	void		(*append)(struct s_arr *, void *);
	void		(*prepend)(struct s_arr *, void *);
	void		(*print)(struct s_arr *);
}				t_arr;

t_arr	*arr_init(
			int max_len, int el_size, t_free_el free_el, t_print_el print_el);
void	arr_clear(t_arr *arr);
t_arr	*arr_resize(t_arr *arr, int max_len, int el_size);
void	arr_set(t_arr *arr, int i, void *el);
void	*arr_get(t_arr *arr, int i);
void	arr_del(t_arr *arr, int i);
void	arr_insert(t_arr *arr, int i, void *el);
void	arr_append(t_arr *arr, void *el);
void	arr_prepend(t_arr *arr, void *el);
void	arr_print(t_arr *arr);

#endif
