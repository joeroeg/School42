/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:27:32 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/29 20:29:31 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
input: ft_memmove(dst, src, 5)
src: 01234
dst: 56789
output: dst = 01234

input: ft_memmove(src + 1, src, 3)
src: 01234
dst: 56789
output: src = 00123
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	if (!dest || !src)
		return (NULL);
	destination = dest;
	source = src;
	if (destination == source)
		return (destination);
	if (destination < source)
		while (n--)
			*destination++ = *source++;
	else if (destination > source)
	{
		destination += n;
		source += n;
		while (n--)
			*(--destination) = *(--source);
	}
	return (destination);
}
