/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:18:43 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/30 22:31:55 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: locates the last occurrence of (c) in the string (s) and returns
		  a pointer to it.
   input: ft_strrchr("Hello", 'l')
  output: "lo"
*/

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*last;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if ((char) c == '\0')
		return ((char *)&s[i]);
	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)last);
}
