#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int num = atoi(argv[1]);
        if (num == 1)
            printf("1");
        int factor = 2;
        while (num > 1)
        {
            while (num % factor == 0)
            {
                printf("%d", factor);
                num /= factor;
                if (num > 1)
                    printf("*");
            }
			factor++;
        }
    }
    printf("\n");
}
