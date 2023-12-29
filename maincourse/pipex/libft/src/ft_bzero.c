/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:35:26 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/30 17:33:26 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: this function is similar to memset,
		  but it sets the first n bytes of the memory area pointed to by s to zero.
   input: ft_bzero("abcdef", 6)
  output: "000000"
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
