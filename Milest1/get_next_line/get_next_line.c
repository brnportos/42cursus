/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brportos <brportos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:12:10 by brportos          #+#    #+#             */
/*   Updated: 2026/02/18 17:20:47 by brportos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_check(char *buf_tmp, char *buf, ssize_t buf_size)
{
	char	*keep_tmp;
	int		len;

	keep_tmp = NULL;
	len = 0;
	if (buf_tmp)
	{
		keep_tmp = ft_strdup(buf_tmp);
		free(buf_tmp);
		len = ft_strlen(keep_tmp) + ft_strlen(buf);
		buf_tmp = malloc(sizeof *buf_tmp * len + 1);
		if (!buf_tmp)
			return (NULL);
		ft_memcpy(buf_tmp, keep_tmp, (ft_strlen(keep_tmp) + 1));
		buf_tmp[ft_strlen(keep_tmp)] = '\0';
		ft_memcpy(ft_strchr(buf_tmp, '\0'), buf, (ft_strlen(buf)));
		buf_tmp[len] = '\0';
		free(keep_tmp);
		keep_tmp = NULL;
	}
	else if (!buf_tmp)
		buf_tmp = ft_strdup(buf);
	return (buf_tmp);
}

void	ft_recopy_after_new_line(char **ptr_buf_tmp)
{
	char	*keep_tmp;

	keep_tmp = ft_strdup(ft_strchr(*ptr_buf_tmp, '\n') + 1);
	free(*ptr_buf_tmp);
	*ptr_buf_tmp = keep_tmp;
}

char	*ft_return_new_line(char **ptr_buf_tmp, char **ptr_buf, ssize_t size)
{
	char	*line;

	line = NULL;
	if (*ptr_buf_tmp && **ptr_buf_tmp && size == 0)
	{
		line = ft_strdup(*ptr_buf_tmp);
		free(*ptr_buf_tmp);
		ptr_buf_tmp = NULL;
		free(*ptr_buf);
		ptr_buf = NULL;
	}
	if (ft_strchr(*ptr_buf_tmp, '\n') != NULL)
	{
		line = ft_substr(*ptr_buf_tmp, 0, ft_strlen(*ptr_buf_tmp)
				- ft_strlen(ft_strchr(*ptr_buf_tmp, '\n') + 1));
		ft_recopy_after_new_line(ptr_buf_tmp);
		return (line);
	}
	free(*ptr_buf_tmp);
	ptr_buf_tmp = NULL;
	free(*ptr_buf);
	ptr_buf = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*buf_tmp;
	char		*line;
	ssize_t		buf_size;

	buf = NULL;
	buf_tmp = NULL;
	buf_size = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (buf_size != 0)
	{
		if (ft_strchr(buf_tmp, '\n') != NULL)
			return (ft_return_new_line(&buf_tmp, &buf, buf_size));
		buf = malloc(sizeof *buf * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		buf_size = read(fd, buf, BUFFER_SIZE);
		if (buf_size <= 0)
			break ;
		buf_tmp = ft_check(buf_tmp, buf, buf_size);
		free(buf);
		buf = NULL;
	}
	return (ft_return_new_line(&buf_tmp, &buf, buf_size));
}
