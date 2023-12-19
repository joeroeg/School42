#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

char *ft_strndup(const char *start, int len)
{
    char *result = malloc((sizeof(char) * (len + 1)));
    if (!result) return NULL;
    for (int i = 0; i < len; i++)
        result[i] = start[i];
    result[len] = '\0';
    return result;
}

char    **ft_split(char *str)
{
    int words = word_count(str);
    int i = 0;
    char **result = malloc(sizeof(char *) * (words + 1));
    if (!result) return NULL;
    while (*str) {
        if (!ft_isspace(*str)) {
            const char *start = str;
            while (!ft_isspace(*str))
                str++;
            int len = str - start;
            result[i++] = ft_strndup(start, len);
        }
        else
            str++;
    }
    result[words] = NULL;
    return (result);
}

char    **ft_split(char *str)
{
	int len = word_count(str);
	char **result = malloc((sizeof(char *) * (len + 1)));
	if (!result) return NULL;
	int i = 0;
	while (*str)
	{
		if (!ft_isspace(*str))
		{
			char *start = str;
			while (!ft_isspace(*str))
				str++;
			int len = str - start;
			result[i++] = ft_strndup(start, len);
		}
		else
			str++;
	}
	return result;
}

int main()
{
    char **str = ft_split("This is a test");
    for (int i = 0; str[i]; i++)
        printf("%s\n", str[i]);
}
