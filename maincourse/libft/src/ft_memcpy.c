/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:05:53 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/26 18:04:56 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	if (!s1 || !s2)
		return (NULL);
	destination = s1;
	source = s2;
	while (n--)
	{
		*destination++ = *source++;
	}
	return (s1);
}
