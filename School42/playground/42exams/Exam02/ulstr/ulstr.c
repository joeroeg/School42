#include <unistd.h>

void ulstr(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            char c = str[i] - 32;
            write(1, &c, 1);
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            char c = str[i] + 32;
            write(1, &c, 1);
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
        ulstr(argv[1]);
    }
    return 0;
}
