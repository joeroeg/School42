#include <stdio.h>
#include <stdarg.h>


int ft_variadit(int n, ...)
{
    va_list ap;
    int i, sum = 0;

    va_start(ap, n); /* Requires the last fixed parameter (to get the address) */
    for (i = 0; i < n; i++)
        sum = va_arg(ap, int); /* Increments ap to the next argument. */
    va_end(ap);

    return sum;
}

int main()
{
    printf("%d", ft_variadit(3, 1, 2, 3));
    return 0;
}