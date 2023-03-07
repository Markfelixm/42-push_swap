#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Libft/ft_printf.h"

typedef struct s_stacks
{
	int	*a;
	int a_len;
	int	*b;
	int b_len;
}		t_stacks;

//Utility
int	*atoi_ptr(const char *str);

#endif
