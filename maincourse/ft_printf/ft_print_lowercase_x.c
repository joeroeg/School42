/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lowercase_x.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:53:21 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/08 17:02:21 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_to_hex_lower(unsigned int num, char *buffer)
{
	char	*hex_chars;
	int		index;

	hex_chars = "0123456789abcdef";
	index = 0;
	if (num == 0)
		buffer[index++] = '0';
	else
	{
		while (num != 0)
		{
			buffer[index++] = hex_chars[num % 16];
			num /= 16;
		}
	}
	buffer[index] = '\0';
}

int	print_and_count_lower(char *buffer)
{
	int	len;
	int	index;

	len = 0;
	index = ft_strlen(buffer);
	while (index > 0)
	{
		write(1, &buffer[--index], 1);
		len++;
	}
	return (len);
}

int	ft_print_lowercase_x(va_list *args)
{
	unsigned int	num;
	char			buffer[16];
	int				len;

	num = va_arg(*args, unsigned int);
	ft_memset(buffer, 0, sizeof(buffer));
	unsigned_to_hex_lower(num, buffer);
	len = print_and_count_lower(buffer);
	return (len);
}
