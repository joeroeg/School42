/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector_functions_extra.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:34:05 by hezhukov          #+#    #+#             */
/*   Updated: 2024/04/10 17:34:08 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	is_delim(char c, char delim)
{
	return (c == delim || c == '\0');
}

static	int	word_count(const char *str, char delim)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_delim(*str, delim))
			str++;
		if (*str && !is_delim(*str, delim))
		{
			count++;
			while (*str && !is_delim(*str, delim))
				str++;
		}
	}
	return (count);
}

static	char	*word_dup(const char *start, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = gc_malloc(len + 1);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_gc(char const *s, char c)
{
	int			words;
	char		**split;
	int			i;
	const char	*start;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	split = gc_malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && is_delim(*s, c))
			s++;
		start = s;
		while (*s && !is_delim(*s, c))
			s++;
		if (s > start)
			split[i++] = word_dup(start, s - start);
	}
	split[i] = NULL;
	return (split);
}
