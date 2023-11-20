#include <unistd.h>

int is_whitespace(char c) {
    return (c == ' ' || c == '\t');
}

void first_word(char *str) {
    int i = 0;

    // Skip leading whitespace
    while (is_whitespace(str[i]))
        i++;

    // Print the word until we reach a whitespace or the end of the string
    while (str[i] != '\0' && !is_whitespace(str[i])) {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write(1, "\n", 1);
        return 1;
    }

    first_word(argv[1]);
    write(1, "\n", 1);

    return 0;
}
