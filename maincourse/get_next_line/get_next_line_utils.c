/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:09:21 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/13 17:48:27 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	calculate_combined_length(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;

	if (s1 != NULL)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2 != NULL)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	return (len1 + len2);
}

char	*join_strings(char const *s1, char const *s2, size_t combined_length)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = malloc(combined_length + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			new_str[i] = s1[i];
			i++;
		}
	}
	j = 0;
	if (s2 != NULL)
	{
		while (s2[j] != '\0')
		{
			new_str[i + j] = s2[j];
			j++;
		}
	}
	new_str[i + j] = '\0';
	return (new_str);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	combined_length;
	size_t	i;
	size_t	j;
	char	*new_str;

	combined_length = calculate_combined_length(s1, s2);
	new_str = malloc(combined_length + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			new_str[i] = s1[i];
			i++;
		}
	}
	j = 0;
	if (s2 != NULL)
	{
		while (s2[j] != '\0')
		{
			new_str[i + j] = s2[j];
			j++;
		}
	}
	new_str[i + j] = '\0';
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
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)&s[i]);
		s++;
	}
	if ((char) c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

size_t	find_line_break(char *str)
{
	size_t	i = 0;

	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*allocate_line(char *str, size_t line_length)
{
	char	*line;

	if (str[line_length] == '\n')
	{
		line = malloc(sizeof(char) * (line_length + 2));
	}
	else
	{
		line = malloc(sizeof(char) * (line_length + 1));
	}
	return (line);
}

void copy_line(char *dest, char *src, size_t length)
{
    size_t j = 0;
    while (j < length) {
        dest[j] = src[j];
        j++;
    }
    if (src[length] == '\n') {
        dest[length] = '\n';
        dest[length + 1] = '\0';
    } else {
        dest[length] = '\0';
    }
}

char *update_staticbuffer(char **static_buffer, size_t line_length)
{
    char *new_buffer;
    if ((*static_buffer)[line_length] != '\0') {
        new_buffer = ft_strdup(*static_buffer + line_length + 1);
    } else {
        new_buffer = ft_strdup("");
    }
    free(*static_buffer);
    return new_buffer;
}

char *extract_line(char **static_buffer)
{
    char *line;
    size_t line_length;

    if (!static_buffer || !*static_buffer) {
        return NULL;
    }

    line_length = find_line_break(*static_buffer);
    line = allocate_line(*static_buffer, line_length);
    if (!line) {
        return NULL;
    }

    copy_line(line, *static_buffer, line_length);
    char *new_buffer = update_staticbuffer(static_buffer, line_length);
    if (!new_buffer) {
        free(line);
        return NULL;
    }

    *static_buffer = new_buffer;
    return line;
}

char	*ft_strdup(const char *str)
{
	size_t	length;
	size_t	i;
	char	*duplicate;

	length = ft_strlen(str);
	duplicate = malloc(length + 1);
	i = 0;
	while (i < length + 1)
	{
		duplicate[i] = '\0';
		i++;
	}
	if (!duplicate)
		return (NULL);
	i = 0;
	while (i < length)
	{
		duplicate[i] = str[i];
		i++;
	}
	duplicate[length] = '\0';
	return (duplicate);
}
