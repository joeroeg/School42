#include <stdio.h>
/*
int ft_strlen(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
*/

int ft_strlen(char *str)
{
	char *ptr = str;
	while(*str)
		str++;
	return (str - ptr);
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        int length = ft_strlen(argv[1]);
        printf("%d\n", length);
    }
    return 0;
}
