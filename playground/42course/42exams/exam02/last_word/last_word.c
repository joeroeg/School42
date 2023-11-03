#include <unistd.h>

int is_whitespace(char c) {
    return (c == ' ' || c == '\t');
}

void last_word(char *str) {
    int last_word_start = -1;
    int i = 0;

    while (str[i] != '\0') {
        if (!is_whitespace(str[i])) {
            if (last_word_start == -1 || is_whitespace(str[i - 1])) {
                last_word_start = i;
            }
        }
        i++;
    }

    if (last_word_start != -1) {
        i = last_word_start;
        while (str[i] != '\0' && !is_whitespace(str[i])) {
            write(1, &str[i], 1);
            i++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write(1, "\n", 1);
        return 1;
    }

    last_word(argv[1]);
    write(1, "\n", 1);

    return 0;
}
