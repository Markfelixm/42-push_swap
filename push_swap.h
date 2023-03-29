/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:44:52 by marmulle          #+#    #+#             */
/*   Updated: 2023/03/29 18:36:16 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/ft_printf.h"
# include "Libft/get_next_line_bonus.h"
# include "Libft/libft.h"

# include <stdbool.h>

# define OPS_MAX_LEN 10000

typedef enum e_op
{
	NONE,
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

typedef struct s_ops
{
	t_op	*ops;
	int		len;
}			t_ops;

typedef struct s_elem
{
	int		n;
	int		order;
	t_ops	*moves;
}			t_elem;

typedef struct s_stacks
{
	t_elem	*a;
	int		a_len;
	int		a_start;

	t_elem	*b;
	int		b_len;
	int		b_start;

	int		max_len;
}			t_stacks;

typedef struct s_three
{
	int	top;
	int	mid;
	int	bot;
}		t_three;

// TODO: REMOVE
// DEBUGGGGGG
void		debug(t_stacks *stacks);

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

// Super Operations
t_op		smart_rotate(t_stacks *stacks, int i, char stack);
t_ops		*index_to_top(t_stacks *stacks, int i, char stack);
t_ops		*top_to_index(t_stacks *stacks, int i, char stack);

// Parse
char		*join_args(int ac, char **av);
char		**joined_to_splits(char *joined, int *s);
t_stacks	*splits_to_stack(char **splits, int *count);
t_stacks	*parse_to_stacks(int ac, char **av);

// Print
void		print_ops(t_ops	*ops);
void		print_op(t_op op);

// Clean
void		clean_exit(t_stacks *stacks, t_ops *ops, bool is_error);
void		free_stacks(t_stacks *stacks);
void		free_ops(t_ops *ops);
void		*free_splits(char **splits);

// Initializer
t_stacks	*init_stacks(int ac);
t_ops		*init_ops(void);

// Operation Utility
void		add_op(t_ops *t_ops, t_op op);
void		append_ops(t_ops *target, t_ops *add);
void		do_op(t_stacks *stacks, t_op op);
void		perform_ops(t_stacks *stacks, t_ops *ops);

// Utility
int			*atoi_ptr(const char *str);
bool		is_unique(int num, t_stacks *stacks);
int			get_index(t_stacks *stacks, int i);

// Sort Utility
int			*bubble_sort_a(t_stacks *stacks);
bool		is_sorted(t_stacks *stacks);

// Sort
t_ops		*select_best_moves(t_stacks *stacks);
t_ops		*push_all_but_3(t_stacks *stacks);
t_ops		*sort_a_of_3(t_stacks *stacks);
t_three		get_three(t_stacks *stacks);
int			find_next_order(t_stacks *stacks, int arg, char stack);
t_ops		*mad_sort(t_stacks *stacks);

// Radix
t_ops		*radix(t_stacks *stacks);
void		set_order(t_stacks *stacks);

#endif
