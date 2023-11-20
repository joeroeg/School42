/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:18:43 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/19 18:55:57 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: locates the last occurrence of (c) in the string (s) and returns
		  a pointer to it.
   input: ft_strrchr("Hello World", 'o')
  output: "orld"
*/

/*
char *ft_strrchr(const char *s, int c)
{
	const char *last_occurrence = NULL;
	unsigned char uc = (unsigned char)c;

	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == uc)
			last_occurrence = ((char *)s);
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return ((char *)last_occurrence);
}
*/
