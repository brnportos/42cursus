#include "../include/ft_printf.h"

void	ft_putunnbr(unsigned int nbr, int *len)
{
    if (nbr >= 10)
    {
        ft_putunnbr(nbr / 10, len);
        ft_putunnbr(nbr % 10, len);
    }
    else if (nbr >= 0)
        ft_putchar(nbr + '0', len);
}
