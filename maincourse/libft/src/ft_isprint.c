/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:15:06 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/30 18:15:07 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: checks if a character c is printable within 0x20 (space) to 0x7E (~).
   input: ft_isprint('a')
  output: 1
	note: casts c to unsigned int and subtracts 0x20.
		  this effectively shifts the range so that the lower boundary becomes 0.
		  the upper limit after the shift becomes 0x5F (0x7E - 0x20 = 0x5F).
*/

int	ft_isprint(int c)
{
	return ((unsigned)c - 0x20 < 0x5f);
}
