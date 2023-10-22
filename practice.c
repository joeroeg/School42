#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// void *ft_memchr(const void *s, int c, size_t n) {
//     const unsigned char *source;
//     unsigned char character;
//     size_t i;
//     source = s;
//     character = (unsigned char)c;
//     i = 0;
//     while (i < n) {
//         if (source[i] == character)
//             return ((void *)(source + i));
//         i++;
//     }
//     return (NULL);
// }

// void *ft_memchr(const void *src, int c, size_t n)
// {
// 	const unsigned char *s = src;
// 	c = (unsigned char)c;
// 	while (n && *s != c)
// 	{
// 		s++;
// 		n--;
// 	}
// 	if (n)
// 		return (void *)s;
// 	else
// 		return (0);
// }

// char *ft_strchr(const char *s, int c) {
//     while (*s && c != *s)
//         s++;
//     if (*s == c)
//         return ((char *)s);
//     return (0);
// }

// int	ft_memcmp(const void *s1, const void *s2, size_t n)
// {
// 	const unsigned char	*source1;
// 	const unsigned char	*source2;
// 	size_t				i;
// 	i = 0;
// 	source1 = s1;
// 	source2 = s2;
// 	while (i < n)
// 	{
// 		if (source1[i] != source2[i])
// 			return ((source1[i] - source2[i]));
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_memcmp(const void *s1, const void *s2, size_t n)
// {
// 	while (n-- > 1 && *(unsigned char*)s1 == *(unsigned char*)s2)
// 	{
// 		s1++;
// 		s2++;
// 	}
// 	return (*(unsigned char *) s1 - *(unsigned char *) s2);
// }

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	if (n == 0)
// 		return (0);
// 	while (n-- > 1 && *s1 && *s1 == *s2)
// 	{
// 		s1++;
// 		s2++;
// 	}
// 	return (*(unsigned char *) s1 - *(unsigned char *) s2);
// }

// int  ft_strncmp(const char *s1, const char *s2, size_t n) {
//     if (n == 0)
//         return 0;
//     while (n-- > 1 && *s1 && *s1 == *s2) {
//         s1++;
//         s2++;
//     }
//     if (n == 0 || *s1 == *s2)
//         return 0;
//     return (*(unsigned char *)s1 - *(unsigned char *)s2);
// }

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	if (n == 0)
// 		return (0);
// 	while (n-- > 1 && *s1 && *s1 == *s2)
// 	{
// 		s1++;
// 		s2++;
// 	}
// 	return (*(unsigned char *) s1 - *(unsigned char *) s2);
// }

char	*ft_strnstr(const char *haystack, const char *neddle, size_t len)
{
	size_t	i; // outer loop for haystack string
	size_t	j; // inner loop for neddle string
	size_t	length; // length of neddle string

	if (!neddle[0]) // if neddle is empty string
		return ((char *)haystack); // return haystack
	length = strlen(neddle); // get length of neddle string
	i = 0; // init outer loop counter to 0
	while (i < len && haystack[i]) // outer loop for haystack string 
	{
		j = 0; // init inner loop counter to 0
		while (i + j < len && haystack[i + j] == neddle[j] && j < length) // inner loop for neddle string
			j++; // increment inner loop counter
		if (j == length) // if inner loop counter is equal to length of neddle string
			return ((char *)haystack + i); // return haystack
		i++; // increment outer loop counter
	}
	return (NULL); // return NULL
}

static int	ft_isspace(char c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}

int	ft_atoi(const char *nptr)
{
	int		output;
	int		negative;
	size_t	i;

	output = 0;
	negative = 1;
	i = 0;
	while (isspace(*nptr++))
		// nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			negative = -1;
		nptr++;
	}
	while (isdigit(*nptr))
	{
		output = output * 10 + (*nptr - '0');
		nptr++;
	}
	return (output * negative);
}

	
int main(void)
{
	char *str = "   -1234";
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
}

// int main()
// {
//     // char	s1[] = "abcdefg";
//     // char	s2[] = "d";
//     char   s1[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', '\0'};
//     char   s2[] = {'d', '\0'};

//     size_t	size = 7;

//     char *result_custom;
//     char *result_expected;

//     printf("%s\n", result_custom = ft_strnstr(s1, s2, size));
//     printf("%s\n", result_expected = strstr(s1, s2));
// }

