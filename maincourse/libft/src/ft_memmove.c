/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:27:32 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/30 17:38:42 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: memmove function copies characters from the source to the destination
		  memory block. It is designed to work even if both memory blocks
		  overlap.
   input: str = "abcde"
		  ft_memmove(str + 2, str, 3)
  output: ababc

    note: Difference between memcpy and memmove.
function: memcpy function copies characters from the source to the destination
		  memory block. It is designed to work only if both memory blocks
		  do not overlap.
   input: str = "abcde"
		  ft_memcpy(str + 2, str, 3)
  output: ababa
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
