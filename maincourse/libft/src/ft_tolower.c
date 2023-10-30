/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:02:33 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/29 20:24:47 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
input: ft_tolower('A')
function: convert 'A' to lowercase
output: 'a'
*/

int	ft_tolower(int c)
{
	if (isupper(c))
		return (c | 32);
	return (c);
}
