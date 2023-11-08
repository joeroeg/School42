#include <unistd.h>   // For dup, dup2, pipe, read, close
#include <stdio.h>    // For fflush
#include <stdarg.h>   // For va_list, va_start, va_end
#include <assert.h>
#include <string.h>
#include "ft_printf.h"

int capture_ft_printf(char *buffer, size_t buffer_size, const char *format, ...) {
    int saved_stdout = dup(STDOUT_FILENO);
    if (saved_stdout == -1) {
        perror("dup");
        return -1;
    }

    int pipes[2];
    if (pipe(pipes) == -1) {
        perror("pipe");
        close(saved_stdout);
        return -1;
    }

    if (dup2(pipes[1], STDOUT_FILENO) == -1) {
        perror("dup2");
        close(saved_stdout);
        close(pipes[0]);
        close(pipes[1]);
        return -1;
    }
    close(pipes[1]);

    va_list args;
    va_start(args, format);
    int result = ft_printf(format, args);
    va_end(args);

    fflush(stdout);

    if (dup2(saved_stdout, STDOUT_FILENO) == -1) {
        perror("dup2");
    }
    close(saved_stdout);

    ssize_t num_read = read(pipes[0], buffer, buffer_size - 1);
    if (num_read < 0) {
        perror("read");
        buffer[0] = '\0';
        result = -1;
    } else {
        buffer[num_read] = '\0';
    }
    close(pipes[0]);

    return result;
}

// int main() {
//     char buffer[1024];
//     int result = capture_ft_printf(buffer, sizeof(buffer), "Hello, %s!", "Hello World");

//     if (result < 0) {
//         fprintf(stderr, "ft_printf failed.\n");
//         return EXIT_FAILURE;
//     }

//     printf("Captured output: '%s'\n", buffer);
//     printf("Reported length: %d\n", result);

//     // Check if the reported length matches the string length
//     if ((size_t)result != strlen(buffer)) {
//         fprintf(stderr, "Error: Mismatch between reported length and actual length.\n");
//         return EXIT_FAILURE;
//     }

//     return EXIT_SUCCESS;
// }
