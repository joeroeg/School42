#include "tests.h"  // Include NEW_TESTs.h instead of NEW_TESTs.c
#include "capture.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // NEW_TEST cases for %d format
    NEW_TEST(1, "%d", 3, -10);
    NEW_TEST(2, "%d", 7, -200000);
    NEW_TEST(3, "%d", 8, -6000023);
    NEW_TEST(5, "%d", 2, 10);
    NEW_TEST(6, "%d", 2, 11);
    NEW_TEST(7, "%d", 2, 15);
    NEW_TEST(8, "%d", 2, 16);
    NEW_TEST(9, "%d", 2, 17);
    NEW_TEST(10, "%d", 2, 99);
    NEW_TEST(11, "%d", 3, 100);
    NEW_TEST(12, "%d", 3, 101);
    NEW_TEST(13, "%d", 3, -10);
    NEW_TEST(14, "%d", 3, -11);
    NEW_TEST(15, "%d", 3, -14);
    NEW_TEST(16, "%d", 3, -15);
    NEW_TEST(17, "%d", 3, -16);
    NEW_TEST(18, "%d", 3, -99);
    NEW_TEST(19, "%d", 4, -100);
    NEW_TEST(20, "%d", 4, -101);
    NEW_TEST(21, "%d", 10, 2147483647);
    NEW_TEST(22, "%ld", 11, -2147483648);
    NEW_TEST(23, "%d %d %d %d %d %d %d", 19, 2147483647, -315333088, -315333272, -315333568, 42717011, -315333272, 1899428563);

    return 0;
}

// int main() {
//     // Initialize the random number generator
//     srand((unsigned int)time(NULL));

//     // Create random test cases
//     for (int test_num = 1; test_num <= 1000; ++test_num) {
//         int random_number = rand(); // Generates a random number between 0 and RAND_MAX
//         int expected_length = 0; // You need to determine the expected length based on your ft_printf implementation

//         // For negative numbers
//         if (rand() % 2) {
//             random_number = -random_number;
//         }

//         // Determine the expected length
//         // This is a simplification; you'll need to make this logic match your ft_printf's behavior
//         expected_length = snprintf(NULL, 0, "%d", random_number);

//         NEW_TEST(test_num, "%d", expected_length, random_number);
//     }

//     return 0;
// }
