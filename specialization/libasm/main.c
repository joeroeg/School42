#include <stdio.h>

extern long ft_strlen(const char *str);

int main() {
    const char *test_str = "Hello, world!";
    long length = ft_strlen(test_str);
    printf("Length of '%s' is: %ld\n", test_str, length);
    return 0;
}
