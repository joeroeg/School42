// #include <stdio.h>
// #include <string.h>
// #include "test_utils.h"
// #include "your_library.h"

// void test_ft_memset_basic() {
//     char buffer[50];
//     char expected[50];

//     // Set both 'buffer' and 'expected' to some known state.
//     memset(buffer, 'A', sizeof(buffer)-1);
//     buffer[sizeof(buffer)-1] = '\0'; // Null-terminate.
//     memset(expected, 'A', sizeof(expected)-1);
//     expected[sizeof(expected)-1] = '\0'; // Null-terminate.

//     // Test 1: Typical usage
//     memset(buffer, 'A', 10);
//     buffer[10] = '\0'; // Null-terminating for safe printing
//     TEST_FUNC(ft_memset, buffer, buffer, 'A', 10);

//     // Test 2: Setting with a different character
//     memset(buffer, 'B', 5);
//     buffer[5] = '\0';
//     TEST_FUNC(ft_memset, buffer, buffer, 'B', 5);

//     // Test 3: Zero length
//     expected[50] = "Hello World"; // Original content
//     strcpy(buffer, "Hello World");
//     TEST_FUNC(ft_memset, buffer, buffer, 'Z', 0);

//     // Add more test cases as needed
// }

// int main() {
//     test_ft_memset();
//     // Call other test functions here
//     return 0;
// }
