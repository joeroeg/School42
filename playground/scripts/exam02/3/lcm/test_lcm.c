#include <stdio.h>
#include <stdlib.h>

unsigned int lcm(unsigned int a, unsigned int b);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: test_lcm num1 num2\n");
        return 1;
    }

    unsigned int num1 = (unsigned int)atoi(argv[1]);
    unsigned int num2 = (unsigned int)atoi(argv[2]);
    unsigned int result = lcm(num1, num2);

    printf("%u\n", result);

    return 0;
}
