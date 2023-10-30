/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:00:51 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/30 18:01:43 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: converts a lower-case letter to the corresponding upper-case letter.
   input: ft_toupper('a')
  output: 'A'
	note: 0x5f = 0101 1111 it is a mask 6th bit is 1 and others are 0 so
		  if we do & operation with this mask and any lower case letter
		  we will get the same letter in upper case.
*/

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c & 0x5f);
	return (c);
}
