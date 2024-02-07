/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uppercase_x.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:53:21 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/08 15:14:08 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_to_hex_upper(unsigned int num, char *buffer)
{
	char	*hex_chars;
	int		index;

	hex_chars = "0123456789ABCDEF";
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

int	print_and_count_upper(char *buffer)
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

int	ft_print_uppercase_x(va_list *args)
{
	unsigned int	num;
	char			buffer[16];
	int				len;

	num = va_arg(*args, unsigned int);
	ft_memset(buffer, 0, sizeof(buffer));
	unsigned_to_hex_upper(num, buffer);
	len = print_and_count_upper(buffer);
	return (len);
}
