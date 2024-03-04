/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:09:01 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/19 18:39:40 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: locates the first occurrence of (c) in the string (s) and returns
		  a pointer to it.
   input: ft_strchr("Hello World", 'o')
  output: "o World"
*/
/*
char *ft_strchr(const char *s, int c)
{
	unsigned char uc;

	uc = (unsigned char)c;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == uc)
			return ((char*)s);
		s++;
	}
	if (uc == '\0')
		return ((char*)s);
	return (0);
}
*/

