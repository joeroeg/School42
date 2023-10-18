/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:27:32 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/18 18:20:54 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	destination = dest;
	source = src;
	if (destination == source)
	{
		return (destination);
	}
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
