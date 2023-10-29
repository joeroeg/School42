/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:11:54 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/28 19:38:53 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
- input: s: "Hello World!", c: 'o', n: 12
- apply: ft_memchr(s, 'o', 12)
- output: "o World!"
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
