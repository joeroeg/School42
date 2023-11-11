/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:29:34 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/10 19:29:49 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: appends the NUL-terminated string (src) to the end of (dest).
		  append at most (size - strlen(dest) - 1) bytes, NUL-terminating the result.
		  returns the total length of the string it tried to create.
   input: ft_strlcat("Hello ", "World!", 12)
  output: 11
  printf: Hello World
*/

/*
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

size_t	concatenate(char *dest, const char *src, size_t destlen, size_t size)
{
	char		*destination;
	const char	*source;
	size_t		remaining_space;

	destination = dest + destlen;
	source = src;
	remaining_space = size - destlen;
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
	return (destlen + (source - src));
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;

	if (!dest || !src)
		return (0);
	destlen = find_dest_length(dest, size);
	if (size == 0 || size <= destlen)
		return (destlen + ft_strlen(src));
	return (concatenate(dest, src, destlen, size));
}
*/
