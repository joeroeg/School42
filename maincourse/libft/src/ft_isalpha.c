/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:14:00 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/29 19:35:29 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
input: ft_isalpha('a')
function: check if 'a' is an alphabet
output: 1
*/

int	ft_isalpha(int c)
{
	return (((unsigned)c | 32) - 'a' < 26);
}
