/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:11:54 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/29 19:26:25 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
input: ft_memchr("abcdef", 'c', 6)
function: find 'c' in "abcdef" within 6 chars
output: "cdef"

input: ft_memchr("abcdef", 'c', 2)
function: find 'c' in "abcdef" within 2 chars
output: NULL
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*string;
	unsigned char		character;

	character = (unsigned char)c;
	string = s;
	if (!s)
		return (NULL);
	while (n--)
	{
		if (*string == character)
			return ((void *)string);
		string++;
	}
	return (NULL);
}
