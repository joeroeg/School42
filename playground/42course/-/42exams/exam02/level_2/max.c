#include <stdio.h>

/*
int max(int *tab, unsigned int len)
{
	if (len == 0)
		return (0);

	unsigned int result;
	unsigned int i = 0;

	result = tab[i];
	while(i < len)
	{
		if (result < tab[i])
		{
			result = tab[i];
		}
		i++;
	}
	return result;
}
*/

int max(int *tab, unsigned int len)
{

}

void test_max()
{
    struct {
        int input[10];
        unsigned int len;
        int expected;
    } test_cases[] = {
        {{1, 2, 3, 4, 5}, 5, 5},
        {{-1, -2, -3, -4, -5}, 5, -1},
        {{10, 9, 8, 7, 6}, 5, 10},
        {{1}, 1, 1},
        {{}, 0, 0}  // Empty array test case
    };

    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {
        int result = max(test_cases[i].input, test_cases[i].len);
        printf("Test %d - Expected: %d, Got: %d\n", i + 1, test_cases[i].expected, result);
    }
}

int main()
{
    test_max();
    return 0;
}

