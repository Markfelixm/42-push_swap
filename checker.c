/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:24:57 by marmulle          #+#    #+#             */
/*   Updated: 2023/04/15 17:51:51 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	if (ac < 2)
		return (42);
	stacks = parse_to_stacks(ac, av);
	if (stacks == NULL)
		clean_exit(stacks, NULL, true);
	set_order(stacks);
	parse_perform_ops(stacks);
	if (is_sorted(stacks) && stacks->b_len == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clean_exit(stacks, NULL, false);
}

void	parse_perform_ops(t_stacks *stacks)
{
	t_ops		*ops;
	t_op		op;

	ops = init_ops(30 * stacks->max_len);
	if (ops == NULL)
		clean_exit(stacks, NULL, true);
	while (42)
	{
		op = parse_op();
		if (op == END)
			break ;
		if (op == NONE)
			clean_exit(stacks, ops, true);
		add_op(ops, op);
	}
	perform_ops(stacks, ops);
	free_ops(ops);
}

t_op	parse_op(void)
{
	t_op	op;
	char	*line;

	line = get_next_line(0);
	if (line == NULL)
		return (END);
	op = get_op(line);
	free(line);
	return (op);
}

t_op	get_op(char *line)
{
	if (ft_strncmp(line, "sa", max(2, ft_strlen(line) - 1)) == 0)
		return (SA);
	if (ft_strncmp(line, "sb", max(2, ft_strlen(line) - 1)) == 0)
		return (SB);
	if (ft_strncmp(line, "ss", max(2, ft_strlen(line) - 1)) == 0)
		return (SS);
	if (ft_strncmp(line, "pa", max(2, ft_strlen(line) - 1)) == 0)
		return (PA);
	if (ft_strncmp(line, "pb", max(2, ft_strlen(line) - 1)) == 0)
		return (PB);
	if (ft_strncmp(line, "ra", max(2, ft_strlen(line) - 1)) == 0)
		return (RA);
	if (ft_strncmp(line, "rb", max(2, ft_strlen(line) - 1)) == 0)
		return (RB);
	if (ft_strncmp(line, "rr", max(2, ft_strlen(line) - 1)) == 0)
		return (RR);
	if (ft_strncmp(line, "rra", max(3, ft_strlen(line) - 1)) == 0)
		return (RRA);
	if (ft_strncmp(line, "rrb", max(3, ft_strlen(line) - 1)) == 0)
		return (RRB);
	if (ft_strncmp(line, "rrr", max(3, ft_strlen(line) - 1)) == 0)
		return (RRR);
	return (NONE);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}
