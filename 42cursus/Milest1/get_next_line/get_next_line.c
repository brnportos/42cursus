/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brportos <brportos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:48:19 by tiarakot          #+#    #+#             */
/*   Updated: 2026/02/20 12:24:28 by brportos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
        size_t  i;
        size_t  src_len;

        i = 0;
        src_len = ft_strlen(src);
        if(!dst || !src)
                return (0);
        if(size == 0)
                return (src_len);
        while (src[i] && i < size -1)
        {
                dst[i] = src[i];
                i++;
        }
        dst[i] = '\0';
        return (i);
}

char	*ft_concatenation(int fd, char *tmp)
{
	char	*buf;
	ssize_t	size;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	size = 1;
	while (!ft_strchr(tmp, '\n') && size > 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
		{
			free(buf);
			buf = NULL;
			free(tmp);
			tmp = NULL;
			return (NULL);
		}
		buf[size] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	free(buf);
	buf = NULL;
	return (tmp);
}


char	*ft_fetch_line(char *tmp)
{
	char	*line;
	int		i;

	i = 0;
	if (!tmp)
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	line = ft_substr(tmp, 0, (i + tmp[i] == '\n'));
	return (line);
}


char	*updating_tmp(char *tmp)
{
	int		i;
	int		j;
	char	*keep_tmp;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	keep_tmp = ft_strdup(tmp + i + 1);
	free(tmp);
	tmp = NULL;
	return (keep_tmp);
}


char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_concatenation(fd, tmp);
	if (!tmp)
		return (NULL);
	line = ft_fetch_line(tmp);
	tmp = updating_tmp(tmp);
	return (line);
}
