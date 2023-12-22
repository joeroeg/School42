#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <inputfile> <command1> <command2> <outputfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *command1 = argv[2];
    const char *command2 = argv[3];
    const char *outputFile = argv[4];

    FILE *fpInput = fopen(inputFile, "r");
    FILE *fpOutput = fopen(outputFile, "w");
    if (fpInput == NULL || fpOutput == NULL) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    // Buffer for reading from input file
    char buffer[1024];

    // Open the first command for reading
    FILE *fpCommand1 = popen(command1, "w");
    if (fpCommand1 == NULL) {
        perror("First command failed");
        fclose(fpInput);
        fclose(fpOutput);
        return EXIT_FAILURE;
    }

    // Write to the first command's stdin from the input file
    while (fgets(buffer, sizeof(buffer), fpInput) != NULL) {
        fputs(buffer, fpCommand1);
    }

    // Close the first command and input file
    pclose(fpCommand1);
    fclose(fpInput);

    // Open the second command for reading
    FILE *fpCommand2 = popen(command2, "r");
    if (fpCommand2 == NULL) {
        perror("Second command failed");
        fclose(fpOutput);
        return EXIT_FAILURE;
    }

    // Read from the second command's stdout and write to the output file
    while (fgets(buffer, sizeof(buffer), fpCommand2) != NULL) {
        fputs(buffer, fpOutput);
    }

    // Close the second command and output file
    pclose(fpCommand2);
    fclose(fpOutput);

    return EXIT_SUCCESS;
}
