#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void custom_export(char *var_name, char *var_value) {
    if (var_name == NULL || var_value == NULL) {
        printf("Syntax error: export command requires variable name and value\n");
        return;
    }

    // Update or add the variable to the environment
    setenv(var_name, var_value, 1);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s variable_name value\n", argv[0]);
        return 1;
    }

    // Extract variable name and value from command line arguments
    char *var_name = argv[1];
    char *var_value = argv[2];

    // Call the custom export function
    custom_export(var_name, var_value);

    // Optional: print the updated environment for demonstration
    extern char **environ;
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }

    return 0;
}
