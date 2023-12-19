#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y)
{
    while (y != 0)
    {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int x = atoi(argv[1]);
        int y = atoi(argv[2]);
        printf("%d", gcd(x, y));
    }
    printf("\n");
}
