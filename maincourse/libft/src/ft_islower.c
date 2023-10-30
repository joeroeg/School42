/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:12:14 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/29 19:32:39 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
input: ft_islower('a')
function: check if 'a' is a lowercase letter
output: 1
*/

int	ft_islower(int c)
{
	return ((unsigned) c - 'a' < 26);
}
