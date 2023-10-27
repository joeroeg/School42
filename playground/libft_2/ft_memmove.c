/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhukov <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:16:00 by hzhukov           #+#    #+#             */
/*   Updated: 2022/12/27 18:37:55 by hzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*destination;

	source = (char *)src;
	destination = (char *)dst;
	if (!dst && !src)
		return (NULL);
	if (destination > source)
	{
		while (len--)
		{
			*(destination + len) = *(source + len);
		}
	}
	else
	{
		while (len--)
		{
		*(destination++) = *(source++);
		}
	}
	return (dst);
}
