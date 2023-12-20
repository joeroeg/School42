#include <stdio.h>

int ft_atoi(const char *str);

int main() {
    // Test cases
    char *tests[] = {"42", "-42", "   42", "+42", "abc42", "42abc", "42abc42", "", "2147483647", "-2147483648"};
    int expected[] = {42, -42, 42, 42, 0, 42, 42, 0, 2147483647, -2147483648};

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int failed = 0;

    for (int i = 0; i < num_tests; i++) {
        int result = ft_atoi(tests[i]);
        if (result != expected[i]) {
            printf("Test failed for input '%s': Expected %d, got %d\n", tests[i], expected[i], result);
            failed++;
        }
    }

    if (failed == 0) {
        printf("All tests passed!\n");
    } else {
        printf("%d tests failed.\n", failed);
    }

    return 0;
}
