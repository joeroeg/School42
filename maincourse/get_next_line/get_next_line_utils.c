/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:09:21 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/13 20:21:05 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	char	*ptr;

	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_str == NULL)
		return (NULL);
	ptr = new_str;
	while (s1 && *s1)
		*ptr++ = *s1++;
	while (s2 && *s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (new_str);
}

size_t	ft_strlen(const char *s)
{
	const char	*a;

	if (!s)
		return (0);
	a = s;
	while (*s)
		s++;
	return (s - a);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*extract_line(char **static_buffer)
{
    char *line;
    char *new_buffer;
    size_t i;

    if (!static_buffer || !*static_buffer) return NULL;

    i = 0;
    while ((*static_buffer)[i] != '\n' && (*static_buffer)[i] != '\0') i++;

    line = malloc(sizeof(char) * (i + ((*static_buffer)[i] == '\n' ? 2 : 1)));
    if (!line) return NULL;

    for (size_t j = 0; j < i; j++) line[j] = (*static_buffer)[j];
    line[i] = ((*static_buffer)[i] == '\n') ? '\n' : '\0';
    line[i + ((*static_buffer)[i] == '\n' ? 1 : 0)] = '\0';

    new_buffer = ((*static_buffer)[i] != '\0') ? ft_strdup(*static_buffer + i + 1) : strdup("");
    if (!new_buffer) {
        free(line);
        return NULL;
    }

    free(*static_buffer);
    *static_buffer = new_buffer;

    return line;
}

char	*ft_strdup(const char *src)
{
	char	*new_str;
	char	*ptr;

	if (!src)
		return (NULL);
	new_str = calloc(ft_strlen(src) + 1, sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ptr = new_str;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (new_str);
}

