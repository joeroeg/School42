#include <stdio.h>
#include <string.h>


size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i, j;
	for (i = 0; s[i]; i++) {
		for (j = 0; accept[j]; j++) {
			if (s[i] == accept[j])
				break;
		}
		if (accept[j] == '\0')
			return i;
	}
	return i;
}


int main()
{
	char *s1 = "abc123";
	char *s2 = "abc";
	printf("%lu\n", strspn(s1, s2));
	printf("%lu\n", ft_strspn(s1, s2));
}
