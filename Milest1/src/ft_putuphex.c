/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brportos <brportos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:44:02 by brportos          #+#    #+#             */
/*   Updated: 2026/02/14 11:01:25 by brportos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putuphex(unsigned long long nbr, int *len)
{
	char	*base;

	base = malloc(sizeof * base * ft_strlen("01234566789ABCDEF") + 1);
	if (!base)
		return ;
	ft_strlcpy(base, "0123456789ABCDEF", 17);
	if (nbr > 15)
		ft_putuphex(nbr / 16, len);
	ft_putchar(base[nbr % 16], len);
	free(base);
	base = NULL;
}
