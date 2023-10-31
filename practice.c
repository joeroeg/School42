#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char custom_toupper(unsigned int i, char c)
{
	return (char)toupper((int)c);
}


char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (0);
	str = strdup(s);
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}


int main()
{
	char *s = "Hello";
	printf("%s\n", ft_strmapi(s, &custom_toupper));
	return (0);
}

