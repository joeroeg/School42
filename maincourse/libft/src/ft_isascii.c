/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:24:53 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/29 19:32:06 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
input: ft_isascii('a')
function: check if 'a' is an ascii character
output: 1
*/

int	ft_isascii(int c)
{
	return (!(c & ~0x7F));
}
