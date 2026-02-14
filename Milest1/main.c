#include "./include/ft_printf.h"
#include <stdio.h>

int	main()
{
	int	a = 9;
	char	c = 's';
	ft_printf("ft_printf....>%d\n",ft_printf("%p\n", &a));
	printf("printf.........>%d\n", printf("%p\n", &a));
}
