/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:48:26 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/08 13:32:23 by hezhukov         ###   ########.fr       */
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

typedef int (*specifier_func)(va_list *);

specifier_func g_specifiers[128] = {
	['c'] = &ft_print_c,
	['s'] = &ft_print_s,
	['d'] = &ft_print_i,
	['i'] = &ft_print_i,
	['%'] = &ft_print_percentage,
	['p'] = &ft_print_p,
	['u'] = &ft_print_u,
	['x'] = &ft_print_lowercase_x,
	['X'] = &ft_print_uppercase_X,

};


int ft_printf(const char *format, ...)
{
	int len = 0;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (g_specifiers[(int)*format])
				len += g_specifiers[(int)*format](&args);
			format++;
		}
		else
		{
			write(1, format++, 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}
