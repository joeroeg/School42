#include <unistd.h>

void union_strings(char *str1, char *str2) {
    int ascii[128] = {0}; // Initialize an array to keep track of characters using their ASCII values

    // Iterate through the first string and mark characters as seen
    while (*str1 != '\0') {
        if (ascii[(int)*str1] == 0) {
            ascii[(int)*str1] = 1;
            write(1, str1, 1);
        }
        str1++;
    }

    // Iterate through the second string and mark characters as seen
    while (*str2 != '\0') {
        if (ascii[(int)*str2] == 0) {
            ascii[(int)*str2] = 1;
            write(1, str2, 1);
        }
        str2++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        write(1, "\n", 1);
    } else {
        union_strings(argv[1], argv[2]);
        write(1, "\n", 1);
    }
    return 0;
}
