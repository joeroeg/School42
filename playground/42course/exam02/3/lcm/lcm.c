#include <unistd.h>
#include <stdio.h>

unsigned int    gcd(unsigned int a, unsigned int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
    if ((int)a <= 0 || (int)b <= 0)
        return 0;
    return (a * b / gcd(a, b));
}

// int main()
// {
//     printf("%d", lcm(18, 48));
// }
