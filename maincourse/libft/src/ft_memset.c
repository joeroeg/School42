/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:26:50 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/29 20:15:24 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
input: ft_memset("abcde", '-', 3)
function: fill 3 bytes of "abcde" with '-'
output: "---de"
*/

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*current_byte;
	unsigned char	byte_value;

	if (!ptr)
		return (0);
	current_byte = (unsigned char *)ptr;
	byte_value = (unsigned char)c;
	while (n--)
	{
		*current_byte = byte_value;
		current_byte++;
	}
	return (ptr);
}
