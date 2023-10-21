#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;
	size_t	i;
	size_t	j;

	if (size == 0)
		return (strlen(src));
	dest_len = strlen(dest);
	src_len = strlen(src);
	total_len = dest_len + src_len;
	i = dest_len;
	j = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (src[i - dest_len] && i < size - 1)
	{
		dest[i] = src[i - dest_len];
		i++;
	}
	dest[i] = '\0';
	return (total_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = strlen(src);
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (srclen);
	if (srclen < dstsize)
	{
		memmove(dst, src, srclen + 1);
	}
	else
	{
		memmove(dst, src, dstsize);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	destination = dest;
	source = src;
	if (destination == source)
	{
		return (destination);
	}
	if (destination < source)
		while (n--)
			*destination++ = *source++;
	else if (destination > source)
	{
		destination += n;
		source += n;
		while (n--)
			*(--destination) = *(--source);
	}
	return (destination);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
 }

int main() {
	char memcpy_str[] = "abcde";
	char memove_str[] = "abcde";
	char strlcpy_str[] = "abcde";
	char strlcat_str[] = "abcde";
	int overlap = 0;

	printf("original: %s\n", memcpy_str);
	ft_memcpy(memcpy_str + overlap, memcpy_str, 3);
	printf("  memcpy: %s\n", memcpy_str);

	printf("\n");

	printf("original: %s\n", memove_str);
	ft_memmove(memove_str + overlap, memove_str, 3);
	printf(" memmove: %s\n", memove_str);

	printf("\n");

	printf("original: %s\n", strlcpy_str);
	ft_strlcpy(strlcpy_str + overlap, strlcpy_str, 3);
	printf(" strlcpy: %s\n", strlcpy_str);

	printf("\n");

	printf("original: %s\n", strlcat_str);
	ft_strlcat(strlcat_str + overlap, strlcat_str, 3);
	printf(" strlcat: %s\n", strlcat_str);
	return 0;
}
