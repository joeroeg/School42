#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(void) {
    char *input;

    // Initialize the Readline library
    using_history();

    while (1) {
        // Prompt the user for input
        input = readline("Enter some text: ");

        // Check for EOF (Ctrl+D)
        if (!input) break;

        // Add input to history
        if (input && *input) add_history(input);

        // Print the input back to the console
        printf("You entered: %s\n", input);

        // Free the allocated input memory
        free(input);
    }

    // Clear the history list and free all the memory
    clear_history();

    return 0;
}
