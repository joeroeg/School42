/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:48:26 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/04 16:12:54 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void ft_putchar(int c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'c')
		{
			char *str = va_args(args, char *);
			ft_putchar(*format);
		}
		else
		{
			ft_putchar(*format);
			format++;
		}
	}
	return 0;
}

int main()
{
	char c = 'A';
	ft_printf("%c", c);
}
