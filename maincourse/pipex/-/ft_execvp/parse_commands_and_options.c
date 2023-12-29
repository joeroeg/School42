#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 10

char **parse_command(const char *cmd) {
    char **argv = malloc((MAX_ARGS + 1) * sizeof(char *));
    if (argv == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    char *temp = strdup(cmd);
    if (temp == NULL) {
        perror("strdup");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    int in_quotes = 0;
    char quote_char = '\0';
    char *arg_start = temp;

    for (char *p = temp; *p != '\0'; p++) {
        // Handle entering and exiting quotes
        if ((*p == '\'' || *p == '"') && (!in_quotes || *p == quote_char)) {
            if (in_quotes) {
                in_quotes = 0;
                *p = '\0';  // Null-terminate the argument
                if (i < MAX_ARGS) {
                    argv[i++] = strdup(arg_start);
                }
            } else {
                in_quotes = 1;
                quote_char = *p;
                arg_start = p + 1;  // Start after the quote
            }
        } else if (*p == ' ' && !in_quotes) {
            *p = '\0';  // Null-terminate the argument
            if (arg_start != p) {  // Avoid empty arguments
                if (i < MAX_ARGS) {
                    argv[i++] = strdup(arg_start);
                }
            }
            arg_start = p + 1;
        }
    }

    if (in_quotes) {
        fprintf(stderr, "Unmatched quote in command\n");
        for (int j = 0; j < i; j++) free(argv[j]);
        free(argv);
        free(temp);
        return NULL;
    }

    // Add the last argument if any and not in quotes
    if (*arg_start != '\0' && !in_quotes && i < MAX_ARGS) {
        argv[i++] = strdup(arg_start);
    }

    argv[i] = NULL; // NULL-terminate the array
    free(temp);
    return argv;
}


void test_parse_command(const char *cmd) {
    char **parsed_args = parse_command(cmd);

    if (parsed_args == NULL) {
        printf("Failed to parse command: %s\n", cmd);
        return;
    }

    printf("Testing command: %s\n", cmd);
    for (int i = 0; parsed_args[i] != NULL; i++) {
        printf("Argument %d: '%s'\n", i, parsed_args[i]);
        free(parsed_args[i]);  // Free each argument
    }
    free(parsed_args);  // Free the argument array
}

int main() {
    test_parse_command("ls -l /home");
    test_parse_command("echo \"hello world\"");
    test_parse_command("grep 'pattern' filename");
    test_parse_command("command \"argument with spaces\" 'another argument'");
    test_parse_command(""); // Edge case: empty string
    test_parse_command("\"\""); // Edge case: empty quoted string

    // Add more test cases as needed
    return 0;
}
