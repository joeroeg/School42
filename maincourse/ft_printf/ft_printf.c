/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:48:26 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/05 22:02:34 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* REQUIREMENTS
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/

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

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t ft_putnbr(int n) {
    unsigned int digit = 0;
    size_t len = 0;  // use size_t for consistency


    if (n < 0) {
        ft_putchar('-');
        digit = (unsigned int)-n;
        len = 1;  // account for the '-' sign
    } else {
        digit = (unsigned int)n;
    }

    if (digit >= 10) {
        ft_putnbr(digit / 10);  // accumulate the length of the recursive calls
    }

    ft_putchar((digit % 10) + '0');
    len += 1;  // increment for each digit

    return len;
}


int ft_printf(const char *format, ...)
{
	int len = 0;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			int x = va_arg(args, int);
			len += ft_putnbr(x);
			format += 2;
		}
		else
		{
			ft_putchar(*format);
			format++;
			len++;
		}
	}
	va_end(args);
	return (len);
}
