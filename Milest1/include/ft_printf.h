#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>

int     ft_printf(const char *format, ...);
void	ft_unputnbr(unsigned int nbr, int *len);
void    ft_putnbr(int nbr, int *len);
void    ft_putstr(char *str, int *len);
void    ft_putchar(char c, int *len);

#endif
