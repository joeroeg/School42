#include "get_next_line.h"
#include <stdio.h>

#define MAX_ALLOCATIONS 1024

typedef struct Allocation {
    void *pointer;
    size_t size;
    const char *file;
    int line;
} Allocation;

Allocation allocations[MAX_ALLOCATIONS];
int allocation_count = 0;


void* custom_malloc(size_t size, const char *file, int line) {
    void *ptr = malloc(size);
    if (ptr && allocation_count < MAX_ALLOCATIONS) {
        allocations[allocation_count++] = (Allocation){ptr, size, file, line};
    }
    return ptr;
}

void custom_free(void *ptr) {
    for (int i = 0; i < allocation_count; i++) {
        if (allocations[i].pointer == ptr) {
            allocations[i] = allocations[--allocation_count];
            break;
        }
    }
    free(ptr);
}

void check_for_memory_leaks() {
    if (allocation_count > 0) {
        printf("Memory leak detected:\n");
        for (int i = 0; i < allocation_count; i++) {
            printf("Leak %d: Size: %zu, Allocated at %s:%d\n",
                   i+1, allocations[i].size, allocations[i].file, allocations[i].line);
        }
    } else {
        printf("No memory leaks detected.\n");
    }
}

#define malloc(size) custom_malloc(size, __FILE__, __LINE__)
#define free(ptr) custom_free(ptr)


int main(void)
{
    int fd1;
	int fd2;
	int fd3;
    char *line;

    // Open three files
	fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    fd3 = open("file3.txt", O_RDONLY);

    // Intentionally create a memory leak

    // char *leaked_memory = malloc(100); // Not freed
    // Use the leaked_memory to avoid compiler warning
    // if (leaked_memory) {
    //     snprintf(leaked_memory, 100, "This is a simulated memory leak.\n");
    //     printf("%s", leaked_memory);
    // }
    // enable for a custom memory free.
    // free(leaked_memory);


    // Read and print one line from each file in a round-robin fashion
    for (int i = 0; i < 3; i++)  // Assuming you want to read 3 lines from each file
    {
        line = get_next_line(fd1);
        if (line)
        {
            printf("%s", line);
            free(line);
        }

        line = get_next_line(fd2);
        if (line)
        {
            printf("%s", line);
            free(line);
        }

        line = get_next_line(fd3);
        if (line)
        {
            printf("%s", line);
            free(line);
        }
    }

    // enable for a custom memory leak detection.
    // check_for_memory_leaks();

	// Close the files
    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}

