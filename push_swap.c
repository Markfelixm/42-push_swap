#include "push_swap.h"

int	is_unique(int num, t_stacks *stacks)
{
	int	index;

	index = 0;
	while (index < stacks->a_len)
		if (stacks->a[index++] == num)
			return (0);
	index = 0;
	while (index < stacks->b_len)
		if (stacks->b[index++] == num)
			return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stacks *stacks;
	int		*num_ptr;
	int		index;

	if (ac < 3)
		return (42);
	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		return (ft_printf("stacks allocation failed\n"));
	stacks->a = malloc(sizeof(int) * ac);
	if (stacks->a == NULL)
		return (ft_printf("stack a allocation failed\n"));
	stacks->a_len = ac - 1;
	stacks->b = malloc(sizeof(int) * ac);
	if (stacks->b == NULL)
		return (ft_printf("stack b allocation failed\n"));
	stacks->b_len = 0;
	index = 0;
	while (index < stacks->a_len)
	{
		num_ptr = atoi_ptr(av[index + 1]);
		if (num_ptr == NULL)
			return (ft_printf("invalid argument\n"));
		if (!is_unique(*num_ptr, stacks))
			return (ft_printf("duplicate arguments\n"));
		stacks->a[index] = *num_ptr;
		free (num_ptr);
		index++;
	}
	// debug
	index = 0;
	while (index < stacks->a_len)
	{
		ft_printf("%d ", stacks->a[index]);
		index++;
	}
	ft_printf("\n");
	// end debug
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	return (0);
}
