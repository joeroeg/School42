#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = (char *)malloc(len + 1);
	if (!s || !new_str)
		return (NULL);
	i = start;
	j = 0;
	while (i < strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len1;

	if (!s1 || !set)
		return (0);
	while (*s1 && strchr(set, *s1))
		s1++;
	len1 = strlen(s1);
	while (len1 && strchr(set, s1[len1]))
		len1--;
	return (ft_substr(s1, 0, len1 + 1));
}

int main()
{
	char *s1 = "Hello World Hello";
	char *set = " Hello ";
	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}
