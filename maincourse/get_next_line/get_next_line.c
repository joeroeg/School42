#include "get_next_line.h"

char *get_next_line(int fd) {
    static char buffer[BUFFER_SIZE + 1];
    static int i = 0;
    static int read_bytes = 0;
    char *line = malloc(BUFFER_SIZE + 1);
    if (!line) return NULL; // Check malloc failure

    int j = 0;
    while (1) {
        if (i >= read_bytes) {
            read_bytes = read(fd, buffer, BUFFER_SIZE);
            if (read_bytes <= 0) { // EOF or error
                free(line);
                return NULL;
            }
            i = 0;
        }

        line[j++] = buffer[i++];
        if (j >= BUFFER_SIZE || buffer[i - 1] == '\n') {
            line[j] = '\0';
            break;
        }
    }

    return line;
}

// int main(void)
// {
// 	int fd[4];
// 	char *tmp[4];
// 	int i;

// 	i = 0;
// 	fd[3] = open("test.txt", O_RDONLY);
// 	for (int i = 0; i < 3; i++)
// 	{
// 		tmp[i] = get_next_line(fd[3]);
// 		printf("fd[0] = %s", tmp[i]);
// 	}
// }
