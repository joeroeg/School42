/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:29:34 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/28 20:37:46 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	find_dest_length(char *dest, size_t size)
{
	char	*destination;
	size_t	n;

	destination = dest;
	n = size;
	while (n-- != 0 && *destination != '\0')
		destination++;
	return (destination - dest);
}

size_t	concatenate(char *dest, const char *src, size_t dlen, size_t size)
{
	char		*destination;
	const char	*source;
	size_t		remaining_space;

	destination = dest + dlen;
	source = src;
	remaining_space = size - dlen;
	while (*source != '\0')
	{
		if (remaining_space != 1)
		{
			*destination++ = *source;
			remaining_space--;
		}
		source++;
	}
	*destination = '\0';
	return (dlen + (source - src));
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t (dlen);
	if (!dest || !src)
		return (0);
	dlen = find_dest_length(dest, size);
	if (size == 0 || size <= dlen)
		return (dlen + ft_strlen(src));
	return (concatenate(dest, src, dlen, size));
}
