/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhukov <hzhukov@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:53:56 by hzhukov           #+#    #+#             */
/*   Updated: 2023/04/04 14:11:01 by hzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

#include <stdarg.h>
#include <stdio.h>

void print_padding(int width, char pad_with) {
    while (width-- > 0) {
        putchar(pad_with);
    }
}

int print_integer(int value, int field_width, char pad_with, int always_print_sign) {
    int num_digits = 0;
    int tmp = value;
    while (tmp > 0) {
        ++num_digits;
        tmp /= 10;
    }
    if (value == 0) {
        ++num_digits;
    } else if (value < 0 || always_print_sign) {
        ++num_digits;
    }
    int padding_width = field_width - num_digits;
    if (padding_width > 0 && !left_justify) {
        print_padding(padding_width, pad_with);
    }
    if (value < 0) {
        putchar('-');
        value = -value;
    } else if (always_print_sign) {
        putchar('+');
    } else if (space_for_positive) {
        putchar(' ');
    }
    if (value == 0) {
        putchar('0');
    } else {
        int digits[10];
        int i = 0;
        while (value > 0) {
            digits[i++] = value % 10;
            value /= 10;
        }
        while (--i >= 0) {
            putchar(digits[i] + '0');
        }
    }
    if (padding_width > 0 && left_justify) {
        print_padding(padding_width, ' ');
    }
    return num_digits;
}

int print_hexadecimal(unsigned int value, int uppercase, int alternate_form, int field_width, char pad_with) {
    char digits[] = "0123456789abcdef";
    if (uppercase) {
        digits = "0123456789ABCDEF";
    }
    int num_digits = 0;
    unsigned int tmp = value;
    while (tmp > 0) {
        ++num_digits;
        tmp /= 16;
    }
    if (value == 0) {
        ++num_digits;
    } else if (alternate_form) {
        num_digits += 2;
    }
    int padding_width = field_width - num_digits;
    if (padding_width > 0 && !left_justify) {
        print_padding(padding_width, pad_with);
    }
    if (alternate_form) {
        putchar('0');
        putchar(uppercase ? 'X' : 'x');
    }
    if (value == 0) {
        putchar('0');
    } else {
        char hex[8];
        int i = 0;
        while (value > 0) {
            hex[i++] = digits[value % 16];
            value /= 16;
        }
        while (--i >= 0) {
            putchar(hex[i]);
        }
    }
    if (padding_width > 0 && left_justify) {
        print_padding(padding_width, ' ');
    }
    return num_digits;
}

int ft_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int written = 0;
    while (*format != '\0') {
        if (*format == '%') {
            ++format;
            
            // parse flags
            int left_justify = 0;
            int pad_with_zero = 0;
            int alternate_form = 0;
            int always_print_sign = 0;
            int space_for_positive = 0;
            while (*format == '-' || *format == '0'
                || *format == '#' || *format == '+' || *format == ' ') {
                    switch (*format) {
                case '-':
                    left_justify = 1;
                    break;
                case '0':
                    pad_with_zero = 1;
                    break;
                case '#':
                    alternate_form = 1;
                    break;
                case '+':
                    always_print_sign = 1;
                    break;
                case ' ':
                    space_for_positive = 1;
                    break;
            }
            ++format;
        }
        
        // parse field width
        int field_width = 0;
        if (*format == '*') {
            field_width = va_arg(args, int);
            ++format;
        } else {
            while (*format >= '0' && *format <= '9') {
                field_width = field_width * 10 + (*format - '0');
                ++format;
            }
        }
        
        // parse conversion specifier
        char conversion_specifier = *format++;
        
        // handle conversion specifier and flags
        int num_digits = 0;
        switch (conversion_specifier) {
            case 'c': {
                char c = (char)va_arg(args, int);
                if (!left_justify) {
                    print_padding(field_width - 1, ' ');
                }
                putchar(c);
                if (left_justify) {
                    print_padding(field_width - 1, ' ');
                }
                ++written;
                break;
            }
            case 's': {
                char *s = va_arg(args, char*);
                int len = strlen(s);
                int padding_width = field_width - len;
                if (padding_width > 0 && !left_justify) {
                    print_padding(padding_width, ' ');
                }
                for (int i = 0; i < len; ++i) {
                    putchar(s[i]);
                    ++written;
                }
                if (padding_width > 0 && left_justify) {
                    print_padding(padding_width, ' ');
                }
                break;
            }
            case 'i':
            case 'd': {
                int value = va_arg(args, int);
                num_digits = print_integer(value, field_width, pad_with_zero ? '0' : ' ', always_print_sign);
                break;
            }
            case 'x':
            case 'X': {
                unsigned int value = va_arg(args, unsigned int);
                num_digits = print_hexadecimal(value, conversion_specifier == 'X', alternate_form, field_width, pad_with_zero ? '0' : ' ');
                break;
            }
            case 'p': {
                void *ptr = va_arg(args, void*);
                unsigned long value = (unsigned long)ptr;
                num_digits = print_hexadecimal(value, 0, 1, field_width, pad_with_zero ? '0' : ' ');
                break;
            }
            case '%': {
                putchar('%');
                ++written;
                break;
            }
            default: {
                // handle invalid format specifier
                break;
            }
        }
        written += num_digits;
    } else {
        putchar(*format++);
        ++written;
    }
}

va_end(args);

return written;
