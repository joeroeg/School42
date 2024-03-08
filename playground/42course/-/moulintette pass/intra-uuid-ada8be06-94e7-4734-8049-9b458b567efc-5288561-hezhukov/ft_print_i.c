/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:42:20 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/08 16:18:43 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_i(va_list *args)
{
	int		num;
	char	*str;
	int		len;

	len = 0;
	num = va_arg(*args, int);
	str = ft_itoa(num);
	if (str)
	{
		len = write(1, str, ft_strlen(str));
		free(str);
	}
	return (len);
}
