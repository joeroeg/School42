#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	size_t j = 0;
	while (s[i])
	{
		j = 0;
		while(reject[j])
		{
			if (s[i] == reject[j])
				return i;
			j++;
		}
		i++;
	}
	return i;
}

// int main()
// {
// 	char *s1 = "abcdef";
// 	char *s2 = "fedcba";
// 	printf("%lu\n", strcspn(s1, s2));
// 	printf("%lu\n", ft_strcspn(s1, s2));
// }
