#include "push_swap.h"

int	*atoi_ptr(const char *str)
{
	int		*ptr;
	long	res;
	char	sign;

	ptr = malloc(sizeof(int));
	if (ptr == NULL)
		return (NULL);
	res = 0;
	sign = 1;
	if (*(str) == '-')
			sign = -1;
	if (*str == '+' || *str == '-')
		++str;
	while (42)
	{
		if (*str == '\0')
			break ;
		if (!ft_isdigit(*str))
			return (NULL);
		res = res * 10 + (*(str++) - '0');
		if (res < INT_MIN || res > INT_MAX)
			return (NULL);
	}
	*ptr = sign * res;
	return (ptr);
}
