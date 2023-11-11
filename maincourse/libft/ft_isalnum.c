/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:59:09 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/10 19:49:20 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: check if 'a' is an alphabet or a number
   input: ft_isalnum('a')
  output: 1
*/

/*
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
*/

int ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
