/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:24:55 by marmulle          #+#    #+#             */
/*   Updated: 2023/04/15 17:51:36 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

t_op	parse_op(void);
t_op	get_op(char *line);
int		max(int a, int b);
void	parse_perform_ops(t_stacks *stacks);

#endif
