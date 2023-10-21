/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:29:34 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/20 12:50:53 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;
	size_t	i;
	size_t	j;

	if (size == 0)
		return (ft_strlen(src));
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	total_len = dest_len + src_len;
	i = dest_len;
	j = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (src[i - dest_len] && i < size - 1)
	{
		dest[i] = src[i - dest_len];
		i++;
	}
	dest[i] = '\0';
	return (total_len);
}
