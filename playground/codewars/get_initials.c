#include <stdio.h>
#include <string.h>
#include <ctype.h>

void nameToInitials(char *firstName, char *lastName) {
    if (strlen(firstName) > 0 && strlen(lastName) > 0) {
        printf("%c.%c\n", toupper(firstName[0]), toupper(lastName[0]));
    } else {
        printf("Invalid input\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <first_name> <last_name>\n", argv[0]);
        return 1;
    }

    char *firstName = argv[1];
    char *lastName = argv[2];

    printf("Initials for %s %s: ", firstName, lastName);
    nameToInitials(firstName, lastName);

    return 0;
}
