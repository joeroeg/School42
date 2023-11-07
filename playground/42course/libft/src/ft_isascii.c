/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:24:53 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/30 18:06:08 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: check if 'a' is an ascii character
   input: ft_isascii('a')
  output: 1
	note: 0x7F = 0111 1111 it is a mask 7th bit is 1 and others are 0 so
		  if we do & operation with this mask and any character
		  we will get 1 if it is an ascii character and 0 if not an ascii character.
		  complement of ~0x7F is = 1000 0000
*/

int	ft_isascii(int c)
{
	return (!(c & ~0x7F));
}
