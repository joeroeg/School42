/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:37:19 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/26 19:10:27 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/*
Description:
strlcpy is a function available in some C libraries (like BSD) but not part of the C Standard Library. It copies up to n-1 characters from a source string to a destination string, null-terminating the result.
It is designed to be safer, more consistent, and less error-prone than strcpy.

Parameters:
dst: Pointer to the destination buffer.
src: Pointer to the null-terminated source string.
n: Size of the destination buffer.

Return Values:
Returns the total length of the source string src. This can be used to detect buffer truncation.

Example:
input: dst: "oldstring", src: "new", n: 4
compute: strlcpy(dst, src, n)
output: dst: "new", returns 3 (length of src)
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (srclen);
	if (srclen < dstsize)
	{
		ft_memcpy(dst, src, srclen + 1);
	}
	else
	{
		ft_memcpy(dst, src, dstsize);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}
