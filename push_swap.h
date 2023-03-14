/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:44:52 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/14 16:33:12 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/ft_printf.h"
# include "Libft/get_next_line_bonus.h"
# include "Libft/libft.h"

typedef enum	e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_op;

typedef struct s_pair
{
	int	n;
	int order;
}		t_pair;

typedef struct s_stacks
{
	t_pair	*a;
	int		a_len;
	int		a_start;

	t_pair	*b;
	int		b_len;
	int		b_start;

	int		max_len;
}			t_stacks;

typedef struct s_ops
{
	t_op	*ops;
	int		len;
}			t_ops;

// Utility
int	*		atoi_ptr(const char *str);
int			is_unique(int num, t_stacks *stacks);
t_stacks	*init_stacks(int ac);
void		clean_stacks(t_stacks *stacks);
int			get_index(t_stacks *stacks, int i);

// Operations
t_op		sa(t_stacks *stacks);
t_op		sb(t_stacks *stacks);
t_op		ss(t_stacks *stacks);
t_op		pa(t_stacks *stacks);
t_op		pb(t_stacks *stacks);
t_op		ra(t_stacks *stacks);
t_op		rb(t_stacks *stacks);
t_op		rr(t_stacks *stacks);
t_op		rra(t_stacks *stacks);
t_op		rrb(t_stacks *stacks);
t_op		rrr(t_stacks *stacks);

#endif
