#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	int	index;

	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;

	if (!s1)
		return (0);
	dest = ft_calloc(sizeof(char), (ft_strlen(s1) + 1));
	if (!dest)
		return (0);
	return (ft_strcpy(dest, s1));
}