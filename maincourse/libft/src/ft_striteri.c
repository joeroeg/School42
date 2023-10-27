/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:55:47 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/26 15:09:33 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
- ft_striteri is used to modify the characters of the input string directly without creating a new string.
- Takes a mutable string (char *s) and a function pointer (void (*f)(unsigned int, char *)) as arguments.
- Iterates through each character of the input string s.
- Applies the function f to each character along with its index.
- Modifies the characters in the original string s in place using the function f.
- The main difference is with ft_strmapi is that it creates a new string with modifications, while ft_striteri modifies the original string in place.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
