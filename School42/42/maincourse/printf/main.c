/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhukov <hzhukov@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:05:16 by hzhukov           #+#    #+#             */
/*   Updated: 2023/04/04 12:39:49 by hzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_printf(const char *format, ...);

int main()
{
    char c = 'A';
    char *str = "Hello, world!";
    int num = 12345;
    void *ptr = &num;
    
    printf("Original printf:\n");
    printf("%%c: %c\n", c);
    printf("%%s: %s\n", str);
    printf("%%i: %i\n", num);
    printf("%%d: %d\n", num);
    printf("%%x: %x\n", num);
    printf("%%X: %X\n", num);
    printf("%%p: %p\n", ptr);
    printf("%%%%: %%\n");
    
    printf("\nCustom ft_printf:\n");
    ft_printf("%%c: %c\n", c);
    ft_printf("%%s: %s\n", str);
    ft_printf("%%i: %i\n", num);
    ft_printf("%%d: %d\n", num);
    ft_printf("%%x: %x\n", num);
    ft_printf("%%X: %X\n", num);
    ft_printf("%%p: %p\n", ptr);
    ft_printf("%%%%: %%\n");
    
    printf("\nAdditional test cases:\n");
    ft_printf("Testing left justification with %%-8i: %-8i\n", num);
    ft_printf("Testing zero-padding with %%06d: %06d\n", num);
    ft_printf("Testing alternative form with %%#x: %#x\n", num);
    ft_printf("Testing space for positive with %% i: % i\n", num);
    ft_printf("Testing always print sign with %%+i: %+i\n", num);
    ft_printf("Testing field width with %%10s: %10s\n", str);
    ft_printf("Testing variable field width with %.*s: %.*s\n", 8, str, 4, str);
    ft_printf("Testing null string with %%s: %s\n", NULL);
    ft_printf("Testing invalid format specifier with %%q: %q\n");
    
    return 0;
}
