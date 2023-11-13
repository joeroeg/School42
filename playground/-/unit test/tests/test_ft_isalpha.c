#include "test_utils.h"
#include "your_library.h"
#include <stdlib.h>
#include <time.h>

void test_ft_isalpha() {
    INIT_TESTS();
    srand((unsigned int)time(NULL)); // Seed the random number generator

    for (int i = 0; i < 127; ++i) { // Run the test 100 times with random input
        char random_char = (char)(rand() % 256); // Generate a random character
        bool expected = isalpha(random_char); // Using the standard library for expected result
        bool passed = ft_isalpha(random_char) == expected;
        RECORD_TEST(passed);
    }

    PRINT_TEST_RESULTS(ft_isalpha);
}

int main() {
    test_ft_isalpha();
    // ... call other test functions ...

    printf("\nTotal tests run: %d\n", tests_run);
    printf("Tests passed: %d\n", tests_passed);
    printf("Tests failed: %d\n", tests_run - tests_passed);

    return 0;
}

