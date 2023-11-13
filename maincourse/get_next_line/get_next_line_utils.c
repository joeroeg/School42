#include "get_next_line.h"

char *ft_strjoin(char const *s1, char const *s2) {
    size_t len1 = s1 ? ft_strlen(s1) : 0;
    size_t len2 = s2 ? ft_strlen(s2) : 0;
    char *new_str = malloc(len1 + len2 + 1);

    if (new_str == NULL) {
        return NULL;
    }

    if (s1) {
        ft_strlcpy(new_str, s1, len1 + 1);
    } else {
        new_str[0] = '\0'; // Start with an empty string if s1 is NULL
    }

    if (s2) {
        ft_strlcat(new_str, s2, len1 + len2 + 1);
    }

    return new_str;
}


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

size_t	find_dest_length(char *dest, size_t size)
{
	char	*destination;
	size_t	n;

	destination = dest;
	n = size;
	while (n-- != 0 && *destination != '\0')
		destination++;
	return (destination - dest);
}

size_t	concatenate(char *dest, const char *src, size_t destlen, size_t size)
{
	char		*destination;
	const char	*source;
	size_t		remaining_space;

	destination = dest + destlen;
	source = src;
	remaining_space = size - destlen;
	while (*source != '\0')
	{
		if (remaining_space != 1)
		{
			*destination++ = *source;
			remaining_space--;
		}
		source++;
	}
	*destination = '\0';
	return (destlen + (source - src));
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;

	if (!dest || !src)
		return (0);
	destlen = find_dest_length(dest, size);
	if (size == 0 || size <= destlen)
		return (destlen + ft_strlen(src));
	return (concatenate(dest, src, destlen, size));
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

char *extract_line(char **static_buffer) {
    char *line;
    char *new_buffer;
    size_t i;

    if (!static_buffer || !*static_buffer) return NULL;

    i = 0;
    while ((*static_buffer)[i] != '\n' && (*static_buffer)[i] != '\0') i++;

    line = malloc(sizeof(char) * (i + ((*static_buffer)[i] == '\n' ? 2 : 1)));
    if (!line) return NULL;

    for (size_t j = 0; j < i; j++) line[j] = (*static_buffer)[j];
    line[i] = ((*static_buffer)[i] == '\n') ? '\n' : '\0';
    line[i + ((*static_buffer)[i] == '\n' ? 1 : 0)] = '\0';

    new_buffer = ((*static_buffer)[i] != '\0') ? ft_strdup(*static_buffer + i + 1) : strdup("");
    if (!new_buffer) {
        free(line);
        return NULL;
    }

    free(*static_buffer);
    *static_buffer = new_buffer;

    return line;
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
