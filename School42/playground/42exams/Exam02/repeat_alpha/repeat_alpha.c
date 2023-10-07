#include <unistd.h>

void repeat_alpha(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            char c = str[i];
            int count = (c >= 'a' && c <= 'z') ? (c - 'a' + 1) : (c - 'A' + 1);
            for (int j = 0; j < count; j++) {
                write(1, &c, 1);
            }
        } else {
            write(1, &str[i], 1);
        }
        i++;
    }
    write(1, "\n", 1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write(1, "\n", 1);
    } else {
        repeat_alpha(argv[1]);
    }
    return 0;
}
