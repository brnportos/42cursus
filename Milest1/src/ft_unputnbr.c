#include "../include/ft_printf.h"

void	ft_unputnbr(unsigned int nbr, int *len)
{
    if (nbr >= 10)
    {
        ft_unputnbr(nbr / 10, len);
        ft_unputnbr(nbr % 10, len);
    }
    else if (nbr >= 0)
        ft_putchar(nbr + '0', len);
}
