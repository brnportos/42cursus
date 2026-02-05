/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brportos <brportos@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 02:17:48 by brportos          #+#    #+#             */
/*   Updated: 2026/02/05 08:11:58 by brportos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	if (!n)
		return (1);
	len = 0;
	if (n < 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned long	nbr;
	int				len;
	char			*str;

	len = ft_len(n);
	str = malloc(sizeof * str * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		nbr = (unsigned int)-n;
	else
		nbr = (unsigned int)n;
	while (len > 0)
	{
		str[len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
		if (n < 0 && len == 1)
			break ;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
