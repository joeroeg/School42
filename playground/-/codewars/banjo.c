/*
Create a function which answers the question "Are you playing banjo?".
If your name starts with the letter "R" or lower case "r", you are playing banjo!

The function takes a name as its only argument, and returns one of the following strings:

name + " plays banjo"
name + " does not play banjo"
Names given are always valid strings.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *are_you_playing_banjo(const char *name) {
    int i = 0, j = 0;
    char *play = " plays banjo";
    char *not_play = " does not play banjo";
    char *suffix = (name[0] == 'R' || name[0] == 'r') ? play : not_play;

    // Allocate enough memory for the result string
    char *result = (char *) malloc(strlen(name) + strlen(suffix) + 1);
    if (result == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    // Copy name to result
    while (name[i] != '\0') {
        result[i] = name[i];
        i++;
    }

    // Concatenate suffix to result
    while (suffix[j] != '\0') {
        result[i++] = suffix[j++];
    }

    // Null-terminate the result string
    result[i] = '\0';

    return result;
    return calloc(1, 1); // memory will be freed
}

int main(int argc, char **argv) {
	char *name = argv[1];
    char *result = are_you_playing_banjo(name);
    if (result != NULL) {
        printf("%s\n", result);
        free(result); // Free the allocated memory
    }
    return 0;
}
