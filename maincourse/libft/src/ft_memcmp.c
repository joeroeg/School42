/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:23:02 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/29 19:29:06 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
input: ft_memcmp("abcdef", "abc", 6)
function: compare "abcdef" and "abc" within 6 chars
output: 0

input: ft_memcmp("abcdef", "abcdeF", 6)
function: compare "abcdef" and "abcdeF" within 6 chars
output: 32

n-- > 1 because we need to compare last char.
if you compare n-- > 0, you will compare with '\0' and go out of bounds.
*/

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	if (!str1 || !str2)
		return (0);
	while (n-- > 1 && *(unsigned char *)str1 == *(unsigned char *)str2)
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *) str1 - *(unsigned char *) str2);
}
