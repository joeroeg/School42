/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:01:07 by hezhukov          #+#    #+#             */
/*   Updated: 2023/12/31 17:01:33 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_snprintf(char *str, size_t size, const char *format, ...) {
    va_list args;
    va_start(args, format);

    const char *p;
    char *buf_ptr = str;
    int total_written = 0;

    for (p = format; *p != '\0'; p++) {
        if (*p != '%') {
            if (total_written < size - 1) {
                *buf_ptr++ = *p;
            }
            total_written++;
            continue;
        }

        p++; // Move past the '%'

        if (*p == 's') {
            const char *val_str = va_arg(args, const char*);
            while (*val_str) {
                if (total_written < size - 1) {
                    *buf_ptr++ = *val_str;
                }
                total_written++;
                val_str++;
            }
        } else if (*p == 'd') {
            int val_int = va_arg(args, int);
            char num_buf[20]; // Buffer to hold the string representation of the integer
            snprintf(num_buf, sizeof(num_buf), "%d", val_int);
            char *num_ptr = num_buf;
            while (*num_ptr) {
                if (total_written < size - 1) {
                    *buf_ptr++ = *num_ptr;
                }
                total_written++;
                num_ptr++;
            }
        }
        // Add support for other specifiers as needed
    }

    va_end(args);

    if (size > 0) {
        *buf_ptr = '\0'; // Null-terminate the string
    }

    return total_written; // Total number of characters written (or would have been written)
}

int main() {
    char buffer[100];
    int length = my_snprintf(buffer, sizeof(buffer), "Hello %s, your score is %d", "Alice", 42);
    printf("Formatted String: %s\n", buffer);
    printf("Length of String: %d\n", length);
    return 0;
}
