#include <stdio.h>
<<<<<<< HEAD
#include <string.h>

char *my_strrev(char *str) {
    int i, j;
    char temp;

    // Length of the string
    int n = strlen(str);

    // Loop from start to half of the string
    for (i = 0, j = n - 1; i < j; i++, j--) {
        // Swap characters at positions i and j
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    return str;
}

int main() {
    char str[] = "Hello, World!";

    printf("Original string: %s\n", str);
    my_strrev(str);
    printf("Reversed string: %s\n", str);

    return 0;
=======


int main()
{
	printf("hello world");
>>>>>>> 21b4a32e8566f6c2cae05e26ce546446c73b8a9f
}

