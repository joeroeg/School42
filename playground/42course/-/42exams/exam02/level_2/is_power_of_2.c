#include <stdio.h>
#include <unistd.h>

int is_power_of_2(unsigned int n)
{

}

void test_is_power_of_2()
{
    struct {
        unsigned int input;
        int expected;
    } test_cases[] = {
        {0, 0}, {1, 1}, {2, 1}, {3, 0}, {4, 1}, {5, 0}, {16, 1}, {1024, 1}, {1025, 0}
    };

    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {
        int result = is_power_of_2(test_cases[i].input);
        printf("Test %d - Input: %u, Expected: %d, Got: %d\n",
               i + 1, test_cases[i].input, test_cases[i].expected, result);
    }
}

int main()
{
    test_is_power_of_2();
    return 0;
}

