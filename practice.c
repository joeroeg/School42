#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}


int word_count(char *str)
{
    int inword = 0;
    int words = 0;
    for (int i = 0; str[i]; i++)
    {
        if (!ft_isspace(str[i]) && inword == 0)
        {
            words++;
            inword = 1;
        }
        else if (ft_isspace(str[i]))
            inword = 0;
    }
    return (words);
}

int main()
{
    char *str = "abc def ghi";
    printf("%d", word_count(str));
}
