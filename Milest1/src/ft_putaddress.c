/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brportos <brportos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:40:07 by brportos          #+#    #+#             */
/*   Updated: 2026/02/14 11:00:47 by brportos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putaddress(void *ptr, int *len)
{
	unsigned long long	address;

	if (!ptr)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	address = (unsigned long long)ptr;
	ft_putstr("0x", len);
	ft_putlowhex(address, len);
}
