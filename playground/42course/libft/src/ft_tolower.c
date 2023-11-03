/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:02:33 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/30 18:02:10 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: converts an upper-case letter to the corresponding lower-case letter.
   input: ft_tolower('A')
  output: 'a'
	note: 0x20 = 0010 0000 it is a mask 6th bit is 1 and others are 0 so
		  if we do | operation with this mask and any upper case letter
		  we will get the same letter in lower case.
*/

int	ft_tolower(int c)
{
	if (isupper(c))
		return (c | 32);
	return (c);
}
