/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:11:54 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/19 15:57:04 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*source;
	unsigned char		character;
	size_t				i;

	source = s;
	character = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (source[i] == character)
			return ((void *)(source + i));
		i++;
	}
	return (NULL);
}
