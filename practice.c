#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)&s[i]);
		s++;
	}
	if ((char) c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
int main()
{
	char *str = "Hello World";
	char *ptr = ft_strchr(str, '\0');
	printf("%s\n", ptr);
	return 0;
}
