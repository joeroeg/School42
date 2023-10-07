#include <unistd.h>

void aff_z(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == 'z') {
            write(1, "z\n", 2);
            return;
        }
        i++;
    }
    write(1, "z\n", 2);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write(1, "z\n", 2);
    } else {
        aff_z(argv[1]);
    }
    return 0;
}
