#include <stdio.h>
#include <string.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;

	if (!s1 || !s2)
	{
		return (0);
	}
	while(*s1)
	{
		i = 0;
	   	while(s2[i])
		{
			if(*s1 == s2[i])
				return (char *) s1;
			i++;
		}
		s1++;
	}
	return (0);
}

int main() {
    const char *str = "abcdef";
    const char *chars = "fedcb";

    char *result = ft_strpbrk(str, chars);
	printf("%s\n", result);
    return 0;
}
