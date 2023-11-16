#include "get_next_line.h"

int main(void) {
	const char *file = "test.txt";
    int fd = open(file, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
	char *line;
    while ((line = get_next_line(fd)) != NULL) {
	    printf("1: %s", line);
		free(line);
	}
	close(fd);
    return 0;
}
