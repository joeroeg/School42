#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*a;

	if (!s)
		return (0);
	a = s;
	while (*s)
		s++;
	return (s - a);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (destination == source || n == 0)
		return (dest);
	if (destination < source || destination >= (source + n))
	{
		while (n--)
			*destination++ = *source++;
	}
	else
	{
		destination += n;
		source += n;
		while (n--)
			*(--destination) = *(--source);
	}
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (srclen);
	if (srclen < dstsize)
		ft_memmove(dst, src, srclen + 1);
	else
	{
		ft_memmove(dst, src, dstsize);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}


char	*ft_strdup(const char *str)
{
	size_t	length;
	char	*duplicate;

	length = ft_strlen(str);
	duplicate = malloc(length + 1);
	if (!duplicate)
		return (NULL);
	ft_strlcpy(duplicate, str, length + 1);
	return (duplicate);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	str_len;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (start + len > str_len)
		len = str_len - start;
	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

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
