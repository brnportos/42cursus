#include "../include/ft_printf.h"

void	ft_putnbr(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) = 11;
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		ft_putnbr(nbr, len);
	}
	else if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, len);
		ft_putnbr(nbr % 10, len);
	}
	else
		ft_putchar(nbr + '0', len);
}
