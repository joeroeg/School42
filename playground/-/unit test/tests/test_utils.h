#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

// Global or static variables to keep track of test counts and results string.
static int tests_run = 0;
static int tests_passed = 0;
static char test_results[256] = {0}; // Adjust the size as needed

#define INIT_TESTS() \
    memset(test_results, 0, sizeof(test_results))

#define RECORD_TEST(passed) \
    do { \
        strcat(test_results, (passed) ? "+" : "-"); \
        tests_run++; \
        if (passed) tests_passed++; \
    } while (0)

#define PRINT_TEST_RESULTS(func) \
    printf("%-20s : %s\n", #func, test_results)

#endif // TEST_UTILS_H
