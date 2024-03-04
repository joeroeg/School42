/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:23:02 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/10 19:28:05 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: memcmp compares the first n bytes of memory area str1 and str2.
		  if str1 is found returns an int less than, equal to, or greater than zero.
   input: ft_memcmp("abcdef", "abc", 6)
  output: 0

   input: ft_memcmp("abcdef", "abcdeF", 6)
  output: 32
*/

/*
int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = str1;
	s2 = str2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
*/
