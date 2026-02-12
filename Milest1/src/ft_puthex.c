#include "../include/ft_printf.h"

void    ft_puthex(unsigned long long nbr, int *len)
{
    char    *base;

    base = malloc(sizeof * base * ft_strlen("0123456789abcdef") + 1);
    if (!base)
        return ;
    ft_strlcpy(base, "0123456789abcdef", 17);
    if (nbr > 15)
        ft_puthex(nbr / 16, len);
    ft_putchar(base[nbr % 16], len);
    free(base);
    base = NULL;
}
