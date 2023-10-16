/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:24:53 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/16 15:42:33 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	int	ft_isascii(int c)
	{
		return (!(c & ~0x7F));
	}

#include <stdio.h>

int main() {
    unsigned char test_char = 'A';
    printf("Is '%c' ASCII? %s\n", test_char, ft_isascii(test_char) ? "Yes" : "No");

    test_char = '§';  // A non-ASCII character

    printf("Is '%c' ASCII? %s\n", test_char, ft_isascii(test_char) ? "Yes" : "No");

    return 0;
}
