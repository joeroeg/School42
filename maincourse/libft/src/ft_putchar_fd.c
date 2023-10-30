/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:55:04 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/29 20:16:33 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
input: ft_putchar_fd('a', 1)
function: write 'a' to a file with fd = 1 (stdout)
output: a
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
