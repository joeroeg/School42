#include <unistd.h>
#include <stdlib.h>

/*
int is_valid_arguments(char *str, char *search, char *replace) {
    return (str != NULL && search != NULL && replace != NULL);
}

void search_and_replace(char *str, char search, char replace) {
    if (str == NULL) {
        write(1, "\n", 1);
        return;
    }

    while (*str != '\0') {
        if (*str == search) {
            write(1, &replace, 1);
        } else {
            write(1, str, 1);
        }
        str++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4 || argv[2][1] != '\0' || argv[3][1] != '\0') {
        write(1, "\n", 1);
        return 1;
    }

    char *str = argv[1];
    char search = argv[2][0];
    char replace = argv[3][0];

    search_and_replace(str, search, replace);
    write(1, "\n", 1);

    return 0;
}
*/

int	main(int argc, char *argv[])
{

}
