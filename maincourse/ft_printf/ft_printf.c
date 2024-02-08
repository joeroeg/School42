/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:48:26 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/07 15:11:16 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef int						(*t_specifier_func)(va_list *);

static const t_specifier_func	g_specifiers[127] = {
['c'] = &ft_print_c,
['s'] = &ft_print_s,
['d'] = &ft_print_i,
['i'] = &ft_print_i,
['u'] = &ft_print_u,
['p'] = &ft_print_p,
['%'] = &ft_print_percentage,
['x'] = &ft_print_lowercase_x,
['X'] = &ft_print_uppercase_x,
};

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = 0;
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
