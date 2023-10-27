/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:24:00 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/26 19:03:58 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description:
`strncmp` compares up to n characters of two null-terminated strings and returns an integer based on the comparison.

Parameters:
`str1`: Pointer to the first null-terminated string.
`str2`: Pointer to the second null-terminated string.
`n`: The maximum number of characters to compare.

Return Values:
if return value < 0 then it indicates str1 is less than str2.
if return value > 0 then it indicates str2 is less than str1.
if return value = 0 then it indicates str1 is equal to str2.

Example:
input: s1: "apple", s2: "appstore", n: 3
compute: `ft_strncmp(s1, s2, n)`
output: 0 (Both strings are equal up to the first 3 characters.)
*/

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (!str1 || !str2)
		return (0);
	if (n == 0)
		return (0);
	while (n-- > 1 && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *) str1 - *(unsigned char *) str2);
}
