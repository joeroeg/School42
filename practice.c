#include <stdio.h>
#include <unistd.h>

int is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 0;
    return (n & (n - 1)) == 0;
}


#include <stdio.h>

int is_power_of_2(unsigned int n);

int main() {
    // Test with a range of values
    unsigned int test_values[] = {0, 1, 2, 3, 4, 8, 16, 32, 63, 64, 128, 256, 1024, 2048, 5000};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < num_tests; i++) {
        unsigned int value = test_values[i];
        printf("is_power_of_2(%u) = %d\n", value, is_power_of_2(value));
    }

    return 0;
}

