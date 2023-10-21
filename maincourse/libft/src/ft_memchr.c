/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:11:54 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/20 20:43:52 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
It searches for the first occurrence of a byte (character) in a given block of memory.
It searches from the beginning of the block to the end.
The function returns a pointer to the first occurrence of the byte or a null pointer if the byte is not found.

Parameters
ptr			- pointer to the object to be examined
ch			- bytes to search for
n		- max number of bytes to examine
return		- pointer to the location of the byte, or a null pointer if no such byte is found.

musl
void *memchr(const void *src, int c, size_t n)
{
	const unsigned char *s = src;
	c = (unsigned char)c;
	for (; n && *s != c; s++, n--);
	return n ? (void *)s : 0;
}
*/

void *ft_memchr(const void *src, int c, size_t n)
{
	const unsigned char *s = src;
	c = (unsigned char)c;
	while (n && *s != c)
	{
		s++;
		n--;
	}
	if (n)
		return (void *)s;
	else
		return (0);
}


// void	*ft_memchr(const void *s, int c, size_t n)
// {
// 	const unsigned char	*source;
// 	unsigned char		character;
// 	size_t				i;

// 	source = s;
// 	character = (unsigned char)c;
// 	i = 0;
// 	while (i < n)
// 	{
// 		if (source[i] == character)
// 			return ((void *)(source + i));
// 		i++;
// 	}
// 	return (NULL);
// }
