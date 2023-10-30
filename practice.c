/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:22:54 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/29 19:14:55 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (!str1 || !str2)
		return (0);
	if (n == 0)
		return (0);
	while (n-- > 1 && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *) str1 - *(unsigned char *) str2);
}

int main()
{
	char *big = "abcdef";
	char *little = "abcdefghijklmnop";
	size_t size = 10;
	// printf("%d\n", strncmp(big, little, size));
	printf("%d\n", ft_strncmp(big, little, size));
}
