#include "../include/ft_printf.h"

void    ft_putHEX(int nbr, int *len)
{
    char    *base;

    base = malloc(sizeof * base * ft_strlen("01234566789ABCDEF") + 1);
    if (!base)
        return ;
    ft_strlcpy(base, "0123456789ABCDEF", 17);
    if (nbr > 15)
        ft_putHEX(nbr / 16, len);
    ft_putchar(base[nbr % 16], len);
    free(base);
    base = NULL;
}
