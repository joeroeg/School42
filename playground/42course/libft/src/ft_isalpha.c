/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:14:00 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/01 18:51:57 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: check if 'a' is an alphabet
   input: ft_isalpha('a')
  output: 1
*/

int	ft_isalpha(int c)
{
	return (((unsigned)c | 32) - 'a' < 26);
}
