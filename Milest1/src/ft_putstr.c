/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brportos <brportos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:44:15 by brportos          #+#    #+#             */
/*   Updated: 2026/02/13 11:44:16 by brportos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], len);
		i++;
	}
}
