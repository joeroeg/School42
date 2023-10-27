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

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t i;
// 	size_t j;
// 	char *new_str = malloc(len + 1);
//     if (!new_str)
//         return (NULL);
// 	i = start;
// 	j = 0;
// 	while (i < strlen(s) || i < len)
// 	{
// 		new_str[j++] = s[i++];
// 	}
//     new_str[len] = '\0';
// 	return (new_str);
// }

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	unsigned char		*d;
// 	const unsigned char	*s;
// 	d = dest;
// 	s = src;
// 	if (!dest && !src)
// 		return (NULL);
// 	while (n--)
// 	{
// 		*d++ = *s++;
// 	}
// 	return (dest);
// }

// size_t	ft_strlen(const char *s)
// {
// 	const char	*a;
// 	a = s;
// 	while (*s)
// 		s++;
// 	return (s - a);
// }

// size_t	ft_strlcat(char *dest, const char *src, size_t size)
// {
// 	size_t	dest_len;
// 	size_t	src_len;
// 	size_t	total_len;
// 	size_t	i;
// 	size_t	j;
// 	if (size == 0)
// 		return (ft_strlen(src));
// 	dest_len = ft_strlen(dest);
// 	src_len = ft_strlen(src);
// 	total_len = dest_len + src_len;
// 	i = dest_len;
// 	j = 0;
// 	if (size <= dest_len)
// 		return (src_len + size);
// 	while (src[i - dest_len] && i < size - 1)
// 	{
// 		dest[i] = src[i - dest_len];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (total_len);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	srclen;
// 	srclen = ft_strlen(src);
// 	if (!dst || !src)
// 		return (0);
// 	if (dstsize == 0)
// 		return (srclen);
// 	if (srclen < dstsize)
// 	{
// 		ft_memcpy(dst, src, srclen + 1);
// 	}
// 	else
// 	{
// 		ft_memcpy(dst, src, dstsize);
// 		dst[dstsize - 1] = '\0';
// 	}
// 	return (srclen);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*new_str;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	size_t len1 = ft_strlen(s1);
//     size_t len2 = ft_strlen(s2);
// 	new_str = (char *)malloc(len1 + len2 + 1);
// 	if (new_str == NULL)
// 		return (NULL);
// 	ft_strlcpy (new_str, s1, len1 + 1);
// 	ft_strlcat (new_str, s2, len1 + len2 + 1);
// 	new_str[len1 + len2] = '\0';
// 	return (new_str);
// }

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

char *ft_strchr(const char *s, int c)
{
    while (*s && c != *s)
        s++;
    if (*s == c)
        return ((char *)s);
    return (0);
}

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	size_t	len1;
// 	if (!s1 || !set)
// 		return (0);
// 	while (*s1 && ft_strchr(set, *s1))
// 		s1++;
// 	len1 = ft_strlen(s1);
// 	while (len1 && ft_strchr(set, s1[len1]))
// 		len1--;
// 	return (ft_substr(s1, 0, len1 + 1));
// }

// static int	count(const char *str, char c)
// {
// 	int	i;
// 	int	trigger;

// 	i = 0;
// 	trigger = 0;
// 	while (*str)
// 	{
// 		if (*str != c && trigger == 0)
// 		{
// 			trigger = 1;
// 			i++;
// 		}
// 		else if (*str == c)
// 			trigger = 0;
// 		str++;
// 	}
// 	return (i);
// }

// static int	count(const char *str, char c)
// {
// 	int	i;
// 	int	trigger;
// 	i = 0;
// 	trigger = 0;
// 	while (*str)
// 	{
// 		if (*str != c && trigger == 0)
// 		{
// 			trigger = 1;
// 			i++;
// 		}
// 		else if (*str == c)
// 			trigger = 0;
// 		str++;
// 	}
// 	return (i);
// }

// static char	*word_dup(const char *str, int start, int finish)
// {
// 	char	*word;
// 	int		i;
// 	i = 0;
// 	word = malloc((finish - start + 1) * sizeof(char));
// 	if (!word)
// 		return (NULL);
// 	while (start < finish)
// 	{
// 		word[i++] = str[start++];
// 	}
// 	word[i] = '\0';
// 	return (word);
// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	s_len;
// 	int		index;
// 	char	**split;
// 	if (!s)
// 		return (NULL);
// 	split = malloc((count(s, c) + 1) * sizeof(char *));
// 	if (!split)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	index = -1;
// 	s_len = ft_strlen(s);
// 	while (++i <= s_len)
// 	{
// 		if (s[i] != c && index < 0)
// 			index = i;
// 		else if ((s[i] == c || i == s_len) && index >= 0)
// 		{
// 			split[j++] = word_dup(s, index, i);
// 			index = -1;
// 		}
// 	}
// 	split[j] = 0;
// 	return (split);
// }

// int main() {
//     const char* str = "abc__def";
//     char delimiter = '_';
//     char** words = ft_split(str, delimiter);
//     for (int i = 0; words[i] != NULL; i++) {
//         printf("%s\n", words[i]);
//     }
//     return 0;
// }

// static size_t	get_digits(int n)
// {
// 	size_t	i;
// 	i = 1;
// 	while (n /= 10)
// 		i++;
// 	return (i);
// }

// char *ft_itoa(int n) {
//     char *str_num;
//     size_t digits;
//     long int num;
//     num = n;
//     digits = get_digits(n);
//     if (n < 0) {
//         num *= -1;
//         digits++;
//     }
//     if (!(str_num = (char *)malloc(sizeof(char) * (digits + 1))))
//         return NULL;
//     str_num[digits] = 0;
//     while (digits--) {
//         str_num[digits] = num % 10 + '0';
//         num = num / 10;
//     }
//     if (n < 0)
//         str_num[0] = '-';
//     return str_num;
// }

// int main() {
// 	int n = -1234;
// 	printf("%s\n", ft_itoa(n));
// 	return 0;
// }

// static size_t	count_digits(int n)
// {
// 	size_t	i;
// 	i = 1;
// 	while (n /= 10)
// 		i++;
// 	return (i);
// }

// char *ft_itoa(int n) {
//     char *output_string;
//     size_t number_length;
//     long int input_number;
//     input_number = n;
//     number_length = count_digits(n);
//     if (n < 0)
// 	{
//         input_number *= -1;
// 		number_length++;
// 	}
// 	output_string = (char *)malloc(sizeof(char) * (number_length + 1));
// 	if (!output_string)
// 		return (NULL);
//     output_string[number_length] = 0;
//     while (number_length--)
// 	{
//         output_string[number_length] = input_number % 10 + '0';
//         input_number /= 10;
//     }
//     if (n < 0)
//         output_string[0] = '-';
//     return (output_string);
// }

// #include <stdio.h>
// #include <string.h>

// void *ft_memchr(const void *s, int c, size_t n);

// int main() {
//     int arr[] = {1, 2, 3, 4, 5};
//     int arr2[] = "12345";
//     char str[] = "Hello World!";
//     printf("%s\n", ft_memchr(str, 'o', sizeof(str)));
//     printf("%s\n", ft_strchr(str, 'o'));
//     printf("%d\n", *(int *)ft_memchr(arr, 4, sizeof(arr)));
//     printf("%d\n", *(int *)ft_memchr(arr2, '4', sizeof(arr2)));
//     return 0;
// }

// void *ft_memchr(const void *s, int c, size_t n) {
//     const unsigned char *string = (const unsigned char *)s;

//     while (n--) {
//         if (*string == c) {
//             return (void *)string;
//         }
//         string++;
//     }
//     return NULL;
// }

// // Function to print the elements of the linked list
// void printList(struct Node* head) {
//     struct Node* current = head;
//     while (current != NULL) {
//         printf("%d -> ", current->data);
//         current = current->next;
//     }
//     printf("NULL\n");
// }

// int main() {
//     struct Node* head = NULL; // Initialize an empty linked list

//     // Add nodes to the end of the linked list
//     appendNode(&head, 10);
//     appendNode(&head, 20);
//     appendNode(&head, 30);

//     // Print the linked list
//     printf("Linked List: ");
//     printList(head);

//     // Clean up: Free the allocated memory for the linked list nodes
//     struct Node* current = head;
//     while (current != NULL) {
//         struct Node* temp = current;
//         current = current->next;
//         free(temp);
//     }

//     return 0;
// }









