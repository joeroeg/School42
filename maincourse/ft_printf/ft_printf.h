/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:57:57 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/08 16:30:06 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_print_c(va_list *args);
int		ft_print_s(va_list *args);
int		ft_print_i(va_list *args);
int		ft_print_percentage(va_list *args);
int		ft_print_p(va_list *args);
int		ft_print_u(va_list *args);
int		ft_print_lowercase_x(va_list *args);
int		ft_print_uppercase_x(va_list *args);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);

#endif
