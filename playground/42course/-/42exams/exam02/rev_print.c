#include <unistd.h>
#include <string.h>

void rev_print(char *str) {
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        write(1, &str[i], 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write(1, "\n", 1);
        return 0;
    }

    rev_print(argv[1]);
    write(1, "\n", 1);

    return 0;
}
