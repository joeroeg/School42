/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:24:13 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/08 16:48:36 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptr_to_hex(uintptr_t ptr_val, char *buffer)
{
	char	*hex_chars;
	int		index;

	hex_chars = "0123456789abcdef";
	index = 0;
	if (ptr_val == 0)
	{
		buffer[index++] = '0';
	}
	else
	{
		while (ptr_val != 0)
		{
			buffer[index++] = hex_chars[ptr_val % 16];
			ptr_val /= 16;
		}
	}
	buffer[index] = '\0';
}

int	print_formatted_ptr(char *buffer)
{
	int	len;
	int	index;

	len = 2;
	write(1, "0x", 2);
	index = ft_strlen(buffer);
	while (index > 0)
	{
		write(1, &buffer[--index], 1);
		len++;
	}
	return (len);
}

int	ft_print_p(va_list *args)
{
	uintptr_t	ptr_val;
	char		buffer[17];

	ptr_val = va_arg(*args, uintptr_t);
	ft_memset(buffer, 0, sizeof(buffer));
	ptr_to_hex(ptr_val, buffer);
	return (print_formatted_ptr(buffer));
}
