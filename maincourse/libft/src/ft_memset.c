/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:26:50 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/19 15:57:52 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*pointer;
	unsigned char	value;

	pointer = (unsigned char *)str;
	value = (unsigned char)c;
	while (n--)
	{
		*pointer = value;
		pointer++;
	}
	return (str);
}
