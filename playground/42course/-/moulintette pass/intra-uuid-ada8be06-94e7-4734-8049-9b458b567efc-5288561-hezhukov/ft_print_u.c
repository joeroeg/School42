/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:35:35 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/08 16:28:50 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(unsigned int num)
{
	int	num_digits;

	if (num == 0)
		return (1);
	num_digits = 0;
	while (num != 0)
	{
		num /= 10;
		num_digits++;
	}
	return (num_digits);
}

void	num_to_str(char *buffer, unsigned int num, int num_digits)
{
	int	i;

	i = num_digits - 1;
	while (i >= 0)
	{
		buffer[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	buffer[num_digits] = '\0';
}

int	print_str(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	ft_print_u(va_list *args)
{
	unsigned int	num;
	int				num_digits;
	char			buffer[11];
	int				len;

	num = va_arg(*args, unsigned int);
	num_digits = count_digits(num);
	len = 0;
	if (num < 0)
		num = -num;
	num_to_str(buffer, num, num_digits);
	if (num < 0)
	{
		write(1, "-", 1);
		len++;
	}
	len += print_str(buffer);
	return (len);
}
