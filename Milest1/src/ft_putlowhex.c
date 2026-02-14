/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlowhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brportos <brportos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:43:58 by brportos          #+#    #+#             */
/*   Updated: 2026/02/14 11:01:36 by brportos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putlowhex(unsigned long long nbr, int *len)
{
	char	*base;

	base = malloc(sizeof * base * ft_strlen("0123456789abcdef") + 1);
	if (!base)
		return ;
	ft_strlcpy(base, "0123456789abcdef", 17);
	if (nbr > 15)
		ft_putlowhex(nbr / 16, len);
	ft_putchar(base[nbr % 16], len);
	free(base);
	base = NULL;
}
