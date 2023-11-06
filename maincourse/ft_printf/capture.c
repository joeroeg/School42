#include <unistd.h>   // For dup, dup2, pipe, read, close
#include <stdio.h>    // For fflush
#include <stdarg.h>   // For va_list, va_start, va_end
#include "ft_printf.h"

int capture_ft_printf(char *buffer, size_t buffer_size, const char *format, ...) {
    int saved_stdout = dup(1);
    int pipes[2];
    pipe(pipes);
    dup2(pipes[1], 1);

    va_list args;
    va_start(args, format);
    int result = ft_printf(format, args);
    va_end(args);

    fflush(stdout); // Clean everything from the stdout buffer

    // Restore the original stdout
    dup2(saved_stdout, 1);
    close(saved_stdout);

    // Read what was written to the pipe
    read(pipes[0], buffer, buffer_size);
    buffer[buffer_size - 1] = '\0'; // Null-terminate the buffer

    close(pipes[0]);
    close(pipes[1]);

    return result;
}
