#include <stdio.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	if (!s1 || !s2)
		return (NULL);
	destination = s1;
	source = s2;
	while (n--)
	{
		*destination++ = *source++;
	}
	return (s1);
}

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	if (!s1 || !s2)
		return (NULL);
	destination = s1;
	source = s2;
	if (destination == source)
		return (destination);
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


int main(void)
{
    char source[20] = "Hello World!"; // 12 characters + 1 null character
    char destination[20] = "";
	char src[20] = "Hello World!";
	char dest[15] = "";
	int offset = 50;

	ft_memcpy(destination, source, 12);
	ft_memmove(dest, src, 12);
	printf(" memcpy: %s\n", destination);
	printf("memmove: %s\n", dest);

	printf("---------------------\n");
	for (int i = 0; i <= offset; i++)
	{
		printf("offset = %d\n", i);
	ft_memcpy(source + i, destination, 5);
	ft_memmove(src + i, dest, 5);
	printf(" memcpy: %s\n", source);
	printf("memmove: %s\n", src);
	}

	return (0);
}


