/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:51:08 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/08 14:51:55 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(va_list *args)
{
	const char	*s;
	int			len;

	s = va_arg(*args, const char *);
	len = 0;
	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		write(1, s++, 1);
		len++;
	}
	return (len);
}
