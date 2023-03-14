/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:07:31 by marmulle          #+#    #+#             */
/*   Updated: 2023/02/15 19:15:15 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Core
char	*get_next_line(int fd);
char	*grab_line(char **cache);
char	*handle_eof(char **cache);

// Buffer handling
char	*get_buffer(int fd);
char	*append_buffer(char *cache, char *buffer);

// Utility
size_t	scan_for_newline(char *str);
char	*ft_strldup(const char *str, size_t size);
char	*free_and_null(char	*str);

#endif
