// ft_itoa
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// char	*ft_itoa(int nbr)
// {
//     long num = nbr;
//     int length = (num <= 0) ? 1 : 0;
//     for (long n = num; n != 0; n /= 10, length++);
//     char *str = (char *)malloc(sizeof(char) * (length + 1));
//     if (!str) return NULL;
//     str[length] = '\0';
//     if (num < 0) {
//         str[0] = '-';
//         num = -num;
//     }
//     if (num == 0) str[0] = '0';
//     for (int i = length - 1; i >= (nbr < 0); i--) {
//         str[i] = (num % 10) + '0';
//         num /= 10;
//     }
//     return str;
// }

char	*ft_itoa(int nbr)
{

}

// int main(int argc, char **argv)
// {
//     printf("%s", ft_itoa(-2147483648));
// }
