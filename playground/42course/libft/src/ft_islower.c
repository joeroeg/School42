/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:12:14 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/30 18:06:51 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: check if 'a' is a lowercase letter
   input: ft_islower('a')
  output: 1
	note: subtracting 'a' from any lowercase letter will give us the same letter
		  in decimal system. So if we subtract 'a' from any lowercase letter and
		  the result is less than 26 then it is a lowercase letter.
*/

int	ft_islower(int c)
{
	return ((unsigned) c - 'a' < 26);
}
