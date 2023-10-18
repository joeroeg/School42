#include <stddef.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

int main()
{
    char str[] = "hello world";
    printf("before ft_bzero: %s\n", str);
    ft_bzero(str, 1);
    printf("after ft_bzero: %s\n", str);
}