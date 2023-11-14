/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:09:21 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/14 16:30:29 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

// static char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*new_str;
// 	char	*ptr;

// 	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (new_str == NULL)
// 		return (NULL);
// 	ptr = new_str;
// 	while (s1 && *s1)
// 		*ptr++ = *s1++;
// 	while (s2 && *s2)
// 		*ptr++ = *s2++;
// 	*ptr = '\0';
// 	return (new_str);
// }

// static size_t	ft_strlen(const char *s)
// {
// 	const char	*a;

// 	if (!s)
// 		return (0);
// 	a = s;
// 	while (*s)
// 		s++;
// 	return (s - a);
// }



// static char	*ft_strdup(const char *src)
// {
// 	char	*new_str;
// 	char	*ptr;

// 	if (!src)
// 		return (NULL);
// 	new_str = calloc(ft_strlen(src) + 1, sizeof(char));
// 	if (new_str == NULL)
// 		return (NULL);
// 	ptr = new_str;
// 	while (*src)
// 		*ptr++ = *src++;
// 	*ptr = '\0';
// 	return (new_str);
// }

