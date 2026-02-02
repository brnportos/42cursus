/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brportos <brportos@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:20:49 by brportos          #+#    #+#             */
/*   Updated: 2026/02/01 10:43:43 by brportos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*srce;

	dst = (unsigned char *)dest;
	srce = (unsigned char *)src;
	if (srce < dst)
	{
		while (n-- > 0)
			dst[n] = srce[n];
	}
	else if (srce == dst)
		return (dst);
	else
		ft_memcpy(dst, srce, n);
	return (dest);
}
