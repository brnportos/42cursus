#include "../include/ft_printf.h"

void    ft_putaddress(void *ptr, int *len)
{
    unsigned long long  address;

    if (!ptr)
    {
        ft_putstr("(nil)", len);
        return ;
    }
    address = (unsigned long long)ptr;
    ft_putstr("0x", len);
    ft_puthex(address, len);
}
