/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brportos <brportos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:48:19 by tiarakot          #+#    #+#             */
/*   Updated: 2026/02/19 10:21:24 by brportos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_store(int fd, char *buf_tmp)
{
	char	*buf;
	ssize_t		buf_size;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	buf_size = 1;
	while (!ft_strchr(buf_tmp, '\n') && buf_size > 0)
	{
		buf_size = read(fd, buf, BUFFER_SIZE);
		if (buf_size == -1)
		{
			free(buf);
			buf = NULL;
			free(buf_tmp);
			buf_tmp = NULL;
			return (NULL);
		}
		buf[buf_size] = '\0';
		buf_tmp = ft_strjoin(buf_tmp, buf);
	}
	free(buf);
	buf = NULL;
	return (buf_tmp);
}

char	*extract_line(char *buf_tmp)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf_tmp)
		return (NULL);
	while (buf_tmp[i] && buf_tmp[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buf_tmp[i] && buf_tmp[i] != '\n')
	{
		line[i] = buf_tmp[i];
		i++;
	}
	if (buf_tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_storage(char *buf_tmp)
{
	int		i;
	int		j;
	char	*keep_tmp;

	i = 0;
	while (buf_tmpi] && buf_tmp[i] != '\n')
		i++;
	if (!buf_tmp[i])
	{
		free(buf_tmp);
		buf_tmp = NULL;
		return (NULL);
	}
	keep_tmp = malloc(ft_strlen(buf_tmp) - i + 1);
	if (!keep_tmp)
		return (NULL);
	i++;
	j = 0;
	while (buf_tmp[i])
		keep_tmp[j++] = buf_tmp[i++];
	keep_tmp[j] = '\0';
	free(buf_tmp);
	buf_tmp = NULL;
	return (keep_tmp);
}

char	*get_next_line(int fd)
{
	static char	*buf_tmp;
	char		*line;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	buf_tmp = read_and_store(fd, buf_tmp);
	if (!buf_tmp)
		return (NULL);
	line = extract_line(buf_tmp);
	buf_tmp = update_storage(buf_tmp);
	return (line);
}
