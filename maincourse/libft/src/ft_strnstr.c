/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:29:00 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/18 18:43:57 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *neddle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	length;

	if (!neddle[0])
		return ((char *)haystack);
	length = ft_strlen(neddle);
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		while (i + j < len && haystack[i + j] == neddle[j] && j < length)
			j++;
		if (j == length)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
