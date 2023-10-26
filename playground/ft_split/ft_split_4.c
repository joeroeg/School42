#include <string.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	const char	*a;

	a = s;
	while (*s)
		s++;
	return (s - a);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && c != *s)
		s++;
	if (c == *s)
		return ((char *)s);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	size_t j;
	char *new_str = malloc(len + 1);
    if (!new_str)
        return (NULL);
	i = start;
	j = 0;
	while (i < strlen(s) || i < len)
	{
		new_str[j++] = s[i++];
	}
    new_str[len] = '\0';
	return (new_str);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}

int main() {
    const char* str = "abc__def";
    char delimiter = '_';
    char** words = ft_split(str, delimiter);
    for (int i = 0; words[i] != NULL; i++) {
        printf("%s\n", words[i]);
    }
    return 0;
}