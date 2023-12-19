#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i] != '\0')
	{
		if (ft_strchr(accept, s[i]) == 0)
			break;
		++i;
	}
	return (i);
}

// int main ()
// {
//   int i;
//   char strtext[] = "hello world";
//   char cset[] = "hel";

//   i = strspn (strtext,cset);
//   printf ("The initial text has %lu symbols.\n", strspn(strtext,cset));
//   printf ("The initial text has %lu symbols.\n", ft_strspn(strtext,cset));
//   return 0;
// }
