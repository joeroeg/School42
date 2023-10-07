#include <stdio.h>

int ft_strcpy_pointers(s, t) /* copy t to s; pointer version 2 */
char *s, *t;
{
  while ((*s++ = *++t));
}

int main()
{
    char source[] = "Hello, World!";
    char destination[20];

    ft_strcpy_pointers(destination, source);

    printf("Source string: %s\n", source);
    printf("Copied string: %s\n", destination);

    return 0;
}
