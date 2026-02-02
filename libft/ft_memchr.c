/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brportos <brportos@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:37:34 by brportos          #+#    #+#             */
/*   Updated: 2026/02/01 10:44:02 by brportos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*raw_mem;

	i = 0;
	raw_mem = (unsigned char *)s;
	while (i < n)
	{
		if (raw_mem[i] == (unsigned char)c)
			return ((void *)&raw_mem[i]);
		i++;
	}
	return (NULL);
}
