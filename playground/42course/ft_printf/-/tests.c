// tests.c
#include "ft_printf.h"
#include "tests.h"
#include <stdio.h>
#include <stdarg.h>
#include "capture.h"

void format_test_parameters(char *buffer, size_t buffer_size, const char *format, ...) {
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, buffer_size, format, args);
    va_end(args);
}

void run_test(const char *format, ...) {
    va_list args1, args2;
    int len1, len2;

    va_start(args1, format);
    va_start(args2, format);

    len1 = ft_printf(format, va_arg(args1, int));
    len2 = printf(format, va_arg(args2, int));

    if (len1 == len2) {
        printf("Passed\n");
    } else {
        printf("Failed: ft_printf returned %d, printf returned %d\n", len1, len2);
    }

    va_end(args1);
    va_end(args2);
}
