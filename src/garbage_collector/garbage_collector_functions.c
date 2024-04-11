/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector_functions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:33:58 by hezhukov          #+#    #+#             */
/*   Updated: 2024/04/10 17:34:00 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin_gc(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)gc_malloc(len1 + len2 + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy (new_str, s1, len1 + 1);
	ft_strlcat (new_str, s2, len1 + len2 + 1);
	new_str[len1 + len2] = '\0';
	return (new_str);
}

char	*ft_strdup_gc(const char *str)
{
	size_t	length;
	char	*duplicate;

	length = ft_strlen(str);
	duplicate = gc_malloc(length + 1);
	if (!duplicate)
		return (NULL);
	ft_strlcpy(duplicate, str, length + 1);
	return (duplicate);
}
