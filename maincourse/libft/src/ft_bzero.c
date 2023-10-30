/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:35:26 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/29 19:31:33 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
input: ft_bzero("abcdef", 6)
function: set "abcdef" to 0 within 6 chars
output: "000000"
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
