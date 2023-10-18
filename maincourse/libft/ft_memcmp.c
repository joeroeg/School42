/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:23:02 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/18 18:20:55 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*src1;
	const unsigned char	*src2;
	size_t				i;

	i = 0;
	src1 = s1;
	src2 = s2;
	while (i < n)
	{
		if (src1[i] != src2[i])
			return ((src1[i] - src2[i]));
		i++;
	}
	return (0);
}
