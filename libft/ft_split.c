/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brportos <brportos@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:21:24 by brportos          #+#    #+#             */
/*   Updated: 2026/02/01 14:48:17 by brportos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char s, char c)
{
	if (s == c)
		return (1);
	else
		return (0);
}

static int	count_word(char const *s, char c)
{
	int	i;
	int	word;
	
	i = 0;
	word = 0;
	while (*s)
	{
		if(s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
		s++;
	}
	return (word);
}

static char	*word_dup(char const *s, int len)
{
	int		i;
	char	*dup;

	i = 0;
	if (!s)
		return (NULL);
	dup = malloc(sizeof * dup * (len + 1));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	if (!s)
		return (NULL);
	split = malloc(sizeof * split * (count_word(s, c) + 1));
	if (!split)
		return (NULL);
	while (*s)
	{
		j = 0;
		while (*s && ft_check(*s, c))
			s++;
		while (s[j] && !ft_check(s[j], c))
			j++;
		if (*s)
			split[i++] = word_dup(s, j);
		while (*s && !ft_check(*s, c))
			s++;
	}
	split[i] = NULL;
	return (split);
}
