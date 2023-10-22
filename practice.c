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

// char	*ft_strnstr(const char *haystack, const char *neddle, size_t len)
// {
// 	size_t	i; // outer loop for haystack string
// 	size_t	j; // inner loop for neddle string
// 	size_t	length; // length of neddle string
// 	if (!neddle[0]) // if neddle is empty string
// 		return ((char *)haystack); // return haystack
// 	length = strlen(neddle); // get length of neddle string
// 	i = 0; // init outer loop counter to 0
// 	while (i < len && haystack[i]) // outer loop for haystack string 
// 	{
// 		j = 0; // init inner loop counter to 0
// 		while (i + j < len && haystack[i + j] == neddle[j] && j < length) // inner loop for neddle string
// 			j++; // increment inner loop counter
// 		if (j == length) // if inner loop counter is equal to length of neddle string
// 			return ((char *)haystack + i); // return haystack
// 		i++; // increment outer loop counter
// 	}
// 	return (NULL); // return NULL
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*new_str;
// 	size_t	i;
// 	size_t	j;
// 	new_str = (char *)malloc(len + 1);
// 	if (!s || !new_str)
// 		return (NULL);
// 	i = start;
// 	j = 0;
// 	while (i < strlen(s) && j < len)
// 		new_str[j++] = s[i++];
// 	new_str[j] = '\0';
// 	return (new_str);
// }

// char *ft_substr(const char *s, unsigned int start, size_t len)
// {
//     if (s == NULL) {
//         return NULL; // Handle invalid input.
//     }
//     size_t s_len = strlen(s);
//     if (start >= s_len) {
//         return NULL; // Start index is beyond the end of the string.
//     }
//     // Calculate the actual length of the substring.
//     size_t actual_len = strlen(s) - start;
//     if (actual_len > len) {
//         actual_len = len;
//     }
//     // Allocate memory for the substring (including space for the null terminator).
//     char *substring = (char *)malloc(actual_len + 1);
//     if (substring == NULL) {
//         return NULL; // Memory allocation failed.
//     }
//     // Copy the characters from s to the new memory.
//     strncpy(substring, s + start, actual_len);
//     substring[actual_len] = '\0'; // Null-terminate the substring.
//     return substring;
// }

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

int main(void)
{
    char str[] = "Hello World!";
    char *substr = ft_substr(str, 6, 6);
    printf("%s\n", substr);
    free(substr);
    return (0);
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

