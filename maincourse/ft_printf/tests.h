// tests.h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

#ifndef TESTS_H
#define TESTS_H

void format_test_parameters(char *buffer, size_t buffer_size, const char *format, ...);

#define NEW_TEST(test_num, format, expected, ...) \
    do { \
        char output[1024]; /* Buffer for ft_printf output */ \
        char test_params[256]; /* Buffer for test parameter output */ \
		int result = capture_ft_printf(output, sizeof(output), format, __VA_ARGS__); \
        bool passed = (result == expected); \
        format_test_parameters(test_params, sizeof(test_params), format, __VA_ARGS__); \
        printf("Test %2d | Returned: %2d | Expected: %2d | %s | Input: %-20s \n", \
               test_num, result, expected, (passed ? "✅" : "❌"), test_params); \
    } while(0)


// #define NEW_TEST(test_num, format, expected, ...) \
//     do { \
//         char output[1024]; /* Make sure this buffer is large enough */ \
//         int result = capture_ft_printf(output, sizeof(output), format, __VA_ARGS__); \
//         bool passed = (result == expected); \
//         printf("Test %2d | ", test_num); \
//         printf("Returned: %d | Expected: %d | ", result, expected); \
//         printf("Input: " format, __VA_ARGS__); /* Print the test parameters */ \
//         printf(" -> %s\n", (passed ? "✅" : "❌")); \
//     } while(0)


void run_test(const char *format, ...);

#endif // TESTS_H
