/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:15:06 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/29 20:29:18 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
input: ft_isprint('a')
function: check if 'a' is a printable character
output: 1
*/

int	ft_isprint(int c)
{
	return ((unsigned)c - 0x20 < 0x5f);
}
