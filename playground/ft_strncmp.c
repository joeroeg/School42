#include <string.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- > 1 && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}

int main(void)
{
    char str1[] = "abcdef";
    char str2[] = "abcdefghijklmnop";
    
    // Calculate the difference in memory addresses
    int mem_diff = (int)((unsigned char *)str1 - (unsigned char *)str2);
    
    printf("ft_strncmp: %d\n", ft_strncmp(str1, str2, 6));
    printf("   strncmp: %d\n", strncmp(str1, str2, 6));
    
    // Print memory addresses
    printf("Memory Address str1: %p\n", (void*)str1); // Memory Address str1: 0x7ffee9b127f5 = 140732819122165
    printf("Memory Address str2: %p\n", (void*)str2); // Memory Address str2: 0x7ffee9b12800 = 140732819122176
    
    // Print the calculated memory difference
    printf("Memory Difference: %d\n", mem_diff);
    
    return 0;
}

/*
What would be the result if we have this statement: return ((unsigned char *) s1 - (unsigned char *) s2);
The result would be the difference in memory addresses between the two strings.
So if you convert memory addresses to decimal, you get the difference in memory addresses. For example, if you have two strings:
char str1[] = "abcdef";
char str2[] = "abcdefghijklmnop";
The memory addresses of these two strings are:
Memory Address str1: 0x7ffee9b127f5 = 140732819122165
Memory Address str2: 0x7ffee9b12800 = 140732819122176
The difference in memory addresses is: 140732819122176 - 140732819122165 = 11
*/