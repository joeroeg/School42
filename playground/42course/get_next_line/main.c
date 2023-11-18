#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd1;
	// int fd2;
	// int fd3;
    char *line;

    // Open three files
	fd1 = open("file1.txt", O_RDONLY);
    // fd2 = open("file2.txt", O_RDONLY);
    // fd3 = open("file3.txt", O_RDONLY);

    // Read and print one line from each file in a round-robin fashion
    for (int i = 0; i < 3; i++)  // Assuming you want to read 3 lines from each file
    {
        line = get_next_line(fd1);
        if (line)
        {
            printf("%s", line);
            free(line);
        }

        // line = get_next_line(fd2);
        // if (line)
        // {
        //     printf("%s", line);
        //     free(line);
        // }

        // line = get_next_line(fd3);
        // if (line)
        // {
        //     printf("%s", line);
        //     free(line);
        // }
    }

	// Close the files
    close(fd1);
    // close(fd2);
    // close(fd3);

    return 0;
}

