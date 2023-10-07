#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main() {
    regex_t regex;
    int ret;

    const char *pattern = "hello";
    ret = regcomp(&regex, pattern, 0);
    if (ret) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    const char *string = "hello world";
    int match = regexec(&regex, string, 0, NULL, 0);

    if (!match) {
        printf("Match found!\n");
    } else if (match == REG_NOMATCH) {
        printf("No match found.\n");
    } else {
        char error_buffer[100];
        regerror(match, &regex, error_buffer, sizeof(error_buffer));
        fprintf(stderr, "Regex match failed: %s\n", error_buffer);
        exit(1);
    }

    regfree(&regex);

    return 0;
}
