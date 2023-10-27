/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:41:53 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/26 14:35:03 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
- ft_strmapi is used to create a new string based on the modifications applied to each character of the input string.
- Takes a constant string (char const *s) and a function pointer (char (*f)(unsigned int, char)) as arguments.
- Creates a new string str by duplicating the input string s.
- Iterates through each character of the str and applies the function f to each character along with its index.
- Returns a new string str with the modifications made by the function f.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (0);
	str = ft_strdup(s);
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
