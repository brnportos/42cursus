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

char	*ft_concatenation(int fd, char *keep_tmp)
{
	char	*buf;
	ssize_t	size;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	size = 1;
	while (!ft_strchr(keep_tmp, '\n') && size > 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
		{
			free(buf);
			buf = NULL;
			free(keep_tmp);
			keep_tmp = NULL;
			return (NULL);
		}
		buf[size] = '\0';
		keep_tmp = ft_strjoin(keep_tmp, buf);
	}
	free(buf);
	buf = NULL;
	return (keep_tmp);
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
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
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
	keep_tmp = malloc(ft_strlen(tmp) - i + 1);
	if (!keep_tmp)
		return (NULL);
	i++;
	j = 0;
	while (tmp[i])
		keep_tmp[j++] = tmp[i++];
	keep_tmp[j] = '\0';
	free(tmp);
	tmp = NULL;
	return (keep_tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_concatenation(fd, tmp);
	if (!tmp)
		return (NULL);
	line = ft_fetch_line(tmp);
	tmp = updating_tmp(tmp);
	return (line);
}
