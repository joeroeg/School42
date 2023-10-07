/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhukov <hzhukov@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:05:24 by hzhukov           #+#    #+#             */
/*   Updated: 2023/04/04 12:07:04 by hzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> // write
# include <stdarg.h> // va_list
# include <stdint.h> // uintptr_t

/*ft_main*/
int		ft_printf(const char *format, ...);

/*ft_type*/
int		ft_hex_type(va_list arg, const char low_up);
int		ft_int_type(va_list args);
int		ft_ptr_type(va_list args);
int		ft_str_type(va_list args);
int		ft_unsigned_type(va_list args);

/*ft_len*/
int		ft_hexlen(long n);
int		ft_numlen(long n);
int		ft_ptrlen(uintptr_t ptr);
int		ft_strlen(const char *s);

/*ft_print_utils*/
int		ft_putchar(char c);
void	ft_puthex(unsigned int nb, const char low_up);
void	ft_putnbr(long n);
void	ft_putptr(uintptr_t ptr);
void	ft_putstr(char *str);

#endif
