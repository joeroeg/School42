/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:39:44 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/19 14:41:45 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	calculate_size(int n)
{
	size_t	size;
	long	nbr;

	size = 0;
	nbr = n;
	if (n == 0)
	{
		size = 1;
	}
	else
	{
		if (n < 0)
		{
			size++;
			nbr = -(long)n;
		}
		while (nbr > 0)
		{
			nbr /= 10;
			size++;
		}
	}
	return (size);
}

char	*convert_to_string(int n, size_t size)
{
	char	*str;
	long	nbr;

	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	if (n >= 0)
		nbr = n;
	else
		nbr = -(long)n;
	*(str + size--) = '\0';
	while (nbr > 0)
	{
		*(str + size--) = nbr % 10 + '0';
		nbr /= 10;
	}
	if (size == 0 && str[1] == '\0')
		*(str + size) = '0';
	else if (size == 0 && str[1] != '\0')
		*(str + size) = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	size;

	size = calculate_size(n);
	return (convert_to_string(n, size));
}
