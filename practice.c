#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int	ft_atoi(const char *string)
{
    if (*string == isspace)
        string++;
}

int main()
{
    char *s = " -1234";
    printf("atoi: %d", atoi(s));
}
