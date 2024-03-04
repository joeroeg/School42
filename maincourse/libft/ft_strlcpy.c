/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:37:19 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/19 19:51:46 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: copies up to (dstsize - 1) characters from the string (src) to (dst),
		  NUL-terminating the result if (dstsize) is not 0.
   input: ft_strlcpy("World", "Hello", 3)
  output: He
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t src_len = 0;

	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	while (dstsize > 1 && *src != '\0')
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (src_len);
}
