#include <unistd.h>
#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while (s1 && s2)
    {
        s1[i] = s2[i];
        i++;
    }
    return (s2);
}

int main(int argc, char **argv)
{
    char str1[] = "hello world";
    char str2[] = "";

    ft_strcpy(str1, str2);
    printf("str1: %s \nstr2: %s\n", str1, str2);
}

