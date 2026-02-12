#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>

int     ft_printf(const char *format, ...);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
void    ft_putaddress(void *ptr, int *len);
char    *ft_strcpy(char *dest, const char *src);
void    ft_puthex(unsigned long long nbr, int *len);
void	ft_putunnbr(unsigned int nbr, int *len);
void    ft_putHEX(int nbr, int *len);
void    ft_putnbr(int nbr, int *len);
void    ft_putstr(char *str, int *len);
void    ft_putchar(char c, int *len);

#endif
