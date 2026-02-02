/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brportos <brportos@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 02:17:48 by brportos          #+#    #+#             */
/*   Updated: 2026/02/01 10:44:56 by brportos         ###   ########.fr       */
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
	char			*alpha;

	len = ft_len(n);
	alpha = malloc(sizeof * alpha * (len + 1));
	if (!alpha)
		return (NULL);
	alpha[len] = '\0';
	if (n < 0)
		nbr = (unsigned int)-n;
	else
		nbr = (unsigned int)n;
	while (len > 0)
	{
		alpha[len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
		if (n < 0 && len == 1)
			break ;
	}
	if (n < 0)
		alpha[0] = '-';
	return (alpha);
}
