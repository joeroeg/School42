#include "get_next_line.h"

int main(void) {
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
	char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}

// int main() {
// 	// char *remainder;
// 	char *newline;
//     int fd = open("file.txt", O_RDONLY);
//     if (fd == -1) {
//         perror("Error opening file");
//         return EXIT_FAILURE;
//     }

//     char buffer[1024];
//     ssize_t bytesRead;
//     int newlineFound = 0;
// 	int line_len = 0;

//     while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0 && !newlineFound) {
//         for (int i = 0; i < bytesRead; ++i) {
//             if (buffer[i] == '\n') {
//                 newlineFound = 1;
//                 // Optionally, break here if you want to stop reading immediately after finding the newline
//                 break;
//             }
// 			line_len++;
//         }
//         // Process the buffer here
// 		newline = ft_substr(buffer, 0, line_len);
// 		printf("(%zd) (%s)", bytesRead, newline);
//         // write(STDOUT_FILENO, buffer, line_len + 1);
//     }

//     if (bytesRead == -1) {
//         perror("Error reading file");
//         close(fd);
//         return EXIT_FAILURE;
//     }

//     close(fd);
//     return EXIT_SUCCESS;
// }
