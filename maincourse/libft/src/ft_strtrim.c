/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:33:53 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/30 18:16:25 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: allocates (with malloc) and returns a copy of (s1) with the
		  characters specified in (set) removed from the beginning and the end
		  of the string.
   input: ft_strtrim(" Hello World Hello ", " Hello ")
  output: "World"
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len1;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len1 = ft_strlen(s1);
	while (len1 && ft_strchr(set, s1[len1]))
		len1--;
	return (ft_substr(s1, 0, len1 + 1));
}
