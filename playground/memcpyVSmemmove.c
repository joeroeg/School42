#include <stdio.h>
#include <string.h>

/* musl library implementation*/
void *ft_memmove(void *dest, const void *src, size_t n)
{
	char *d = dest;
	const char *s = src;

	if (d == s)
		return d;
	if ((uintptr_t)s - (uintptr_t)d - n <= -2*n)
		return memcpy(d, s, n);

	if (d < s)
	{
		for (; n; n--) *d++ = *s++;
	}
	else
	{
		while (n) n--, d[n] = s[n];
	}
	return dest;
}

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char		*destination;
// 	const unsigned char	*source;

// 	destination = dest;
// 	source = src;
// 	if (destination == source)
// 	{
// 		return (destination);
// 	}
// 	if (destination < source)
// 		while (n--)
// 			*destination++ = *source++;
// 	else if (destination > source)
// 	{
// 		destination += n;
// 		source += n;
// 		while (n--)
// 			*(--destination) = *(--source);
// 	}
// 	return (destination);
// }

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
    char str[] = "Hello World!";
    char buffer[5];

    printf("\n");
									/* memove */
    // ft_memmove(buffer, str, 5);
    // memmove(buffer, str, 5);
                                    /* memcpy */
    // ft_memcpy(buffer, str, 5);
    memcpy(buffer, str, 5);

    printf("   str: %s\n", str);
    printf("buffer: %s\n", buffer);
    printf("\n");

                                    /* memove */
    // ft_memmove(str + 9, buffer, 5);
    // memmove(str + 9, buffer, 5);
                                    /* memcpy */
    // ft_memcpy(str + 9, buffer, 5);
    memcpy(str + 8, buffer, 5);

    printf("   str: %s\n", str);
    printf("buffer: %s\n", buffer);
    printf("\n");
    // for (int i = 0; i < 13; i++) {
    //     printf("str[%2.d] (%p): %c, buffer[%2.d] (%p): %c\n", i, (void*)&str[i], str[i], i, (void*)&buffer[i], buffer[i]);
    // }
    return 0;
}
