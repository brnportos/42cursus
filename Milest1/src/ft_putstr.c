#include "../include/ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], len);
		i++;
	}
}
