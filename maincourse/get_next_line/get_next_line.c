#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

// char *get_next_line(int fd) {
//     // Assume we know the file size or a maximum size it can be
//     size_t buffer_size = 1024;
//     char *buffer = malloc(buffer_size);

//     if (buffer == NULL) {
//         // Handle memory allocation error
//         return NULL;
//     }

//     ssize_t bytes_read = read(fd, buffer, buffer_size - 1);
//     if (bytes_read == -1) {
//         // Handle read error
//         free(buffer);
//         return NULL;
//     }

//     // Null-terminate the buffer
//     buffer[bytes_read] = '\0';
//     return buffer;
// }

// int main() {
//     int fd = open("file.txt", O_RDONLY);
//     if (fd == -1) {
//         // Handle error
//         return 1;
//     }

//     char *file_contents = get_next_line(fd);
//     if (file_contents != NULL) {
//         // Use the file contents
//         write(STDOUT_FILENO, file_contents, strlen(file_contents));
//         free(file_contents); // Don't forget to free the memory!
//     } else {
//         // Handle error when reading file contents
//     }

//     close(fd);
//     return 0;
// }

#include <stdio.h>

/* getchar: unbuffered single character input */
int ft_getchar(void)
{
	char c;
	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}


int main()
{
	char c;
	while ((c = ft_getchar()) != EOF)
	{
		putchar(c);
	}
	return 0;
}

