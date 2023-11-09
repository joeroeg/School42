#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    char buffer[100];
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1) return 1; // Handle error

    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) return 1; // Handle error

    buffer[bytes_read] = '\0'; // Null-terminate the string
    // Use buffer here

    close(fd);
    return 0;
}
