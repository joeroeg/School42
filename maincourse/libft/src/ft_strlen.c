/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:53:13 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/29 20:21:06 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
input: ft_strlen("Hello")
function: return the length of "Hello"
output: 5
*/

size_t	ft_strlen(const char *s)
{
	const char	*a;

	if (!s)
		return (0);
	a = s;
	while (*s)
		s++;
	return (s - a);
}
