/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:24:17 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/29 19:32:24 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
input: ft_isdigit('1')
function: check if '1' is a digit
output: 1
*/

int	ft_isdigit(int c)
{
	return ((unsigned) c - '0' < 10);
}
