/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:05:53 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/29 20:12:44 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
input: ft_memcpy("-----", "World", 5)
function: copy 5 bytes from "World" to "Hello"
output: dest = "World"
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	if (!dest || !src)
		return (NULL);
	dest_ptr = dest;
	src_ptr = src;
	while (n--)
		*dest_ptr++ = *src_ptr++;
	return (dest);
}
