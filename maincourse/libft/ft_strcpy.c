#include <string.h>
#include <stdio.h>

char    *ft_strcpy(char *s1, const char *s2)
{
    char *start_s1 = s1;

        while (*s2)
        {
            *s1 = *s2;
            s1++;
            s2++;
        }
        *s1 = '\0';
    return (start_s1);
}

int main()
{
    char source[] = "Hello, world!";
    char destination[13];

    ft_strcpy(destination, source);
    printf("Destination: %s\n", destination);

    return 0;
}
