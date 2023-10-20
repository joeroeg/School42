/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:23:02 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/19 15:55:57 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*source1;
	const unsigned char	*source2;
	size_t				i;

	i = 0;
	source1 = s1;
	source2 = s2;
	while (i < n)
	{
		if (source1[i] != source2[i])
			return ((source1[i] - source2[i]));
		i++;
	}
	return (0);
}
