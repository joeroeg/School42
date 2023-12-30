#include <unistd.h>   // for close, dup, dup2, read, write
#include <fcntl.h>    // for open
#include <stdio.h>    // for perror
#include <stdlib.h>   // for exit

/* FREOPEN IMPLEMENTATION */

// int main() {
//     // Redirect standard input to read from a file
//     if (freopen("infile.txt", "r", stdin) == NULL) {
//         perror("freopen() failed");
//         return EXIT_FAILURE;
//     }

//     // Now, any standard input operation will read from "inputfile.txt"
//     char buffer[100];
//     while (fgets(buffer, sizeof(buffer), stdin)) {
//         // Process the line read from the file
//         printf("Read from file: %s", buffer);
//     }

//     // Close the file and reset stdin
//     fclose(stdin);

//     return 0;
// }


/* DUP2 IMPLEMENTATION */

// #define BUFFER_SIZE 1024

// int main() {
//     int file_fd = open("infile.txt", O_RDONLY);
//     if (file_fd < 0) {
//         perror("Failed to open file");
//         exit(EXIT_FAILURE);
//     }

//     // Save the current stdin file descriptor for later restoration
//     int stdin_copy = dup(STDIN_FILENO);
//     if (stdin_copy < 0) {
//         perror("Failed to duplicate stdin");
//         exit(EXIT_FAILURE);
//     }

//     // Redirect stdin to the file
//     if (dup2(file_fd, STDIN_FILENO) < 0) {
//         perror("Failed to redirect stdin to file");
//         exit(EXIT_FAILURE);
//     }

//     close(file_fd);  // Close the original file descriptor

//     // Now, read from stdin (which is redirected from the file)
//     char buffer[BUFFER_SIZE];
//     ssize_t bytes_read;
//     while ((bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
//         // Process the data
//         write(STDOUT_FILENO, buffer, bytes_read);  // For demonstration, write to stdout
//     }

//     // Restore the original stdin
//     dup2(stdin_copy, STDIN_FILENO);
//     close(stdin_copy);

//     return 0;
// }


#define BUFFER_SIZE 1024

// Function to redirect stdin to the specified file
int redirect_stdin(const char *filename) {
    int file_fd = open(filename, O_RDONLY);
    if (file_fd < 0) {
        perror("Failed to open file");
        return -1;
    }

    int stdin_copy = dup(STDIN_FILENO);
    if (stdin_copy < 0) {
        perror("Failed to duplicate stdin");
        close(file_fd);
        return -1;
    }

    if (dup2(file_fd, STDIN_FILENO) < 0) {
        perror("Failed to redirect stdin to file");
        close(file_fd);
        close(stdin_copy);
        return -1;
    }

    close(file_fd);
    return stdin_copy;  // Return the duplicate file descriptor
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Redirect stdin to read from the specified file in argv[1]
    int stdin_copy = redirect_stdin(argv[1]);
    if (stdin_copy < 0) {
        exit(EXIT_FAILURE);
    }

    // Read from the redirected stdin
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    // Restore the original stdin
    dup2(stdin_copy, STDIN_FILENO);
    close(stdin_copy);

    return 0;
}

