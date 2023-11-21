#include <stdio.h>
#include <string.h>

/*
char *ft_strcpy(char *s1, const char *s2) {
    char *original_s1 = s1;
    while (*s2)
        *s1++ = *s2++;
    *s1 = '\0';
    return original_s1;
}
*/

/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
*/


char *ft_strcpy(char *s1, const char *s2)
{
	char *ptr_s1 = s1;
	while(*s2)
		*ptr_s1++ = *s2++;
	*ptr_s1 = '\0';
	return (s1);
}

int main(int argc, char *argv[]) {
    char buffer[1024];

    // Pre-fill the buffer with a known non-null character, e.g., 'X'
    memset(buffer, 'X', sizeof(buffer));

    if (argc == 3) {
        ft_strcpy(buffer, argv[2]);
        buffer[sizeof(buffer) - 1] = '\0'; // Ensure buffer is null-terminated
        printf("%s", buffer);
    }

    return 0;
}

