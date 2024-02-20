#include <stdio.h>
#include <stdlib.h>

// Define a structure to track memory allocations
typedef struct {
    void *ptr;
    size_t size;
    const char *file;
    int line;
} AllocationInfo;

// Declare a global array to store allocation information
#define MAX_ALLOCS 1000
static AllocationInfo allocations[MAX_ALLOCS];
static int num_allocs = 0;

// Custom malloc function
void* my_malloc(size_t size, const char *file, int line) {
    void *ptr = malloc(size);
    if (ptr) {
        if (num_allocs < MAX_ALLOCS) {
            allocations[num_allocs++] = (AllocationInfo){ptr, size, file, line};
        } else {
            fprintf(stderr, "Max number of allocations exceeded\n");
        }
    }
    return ptr;
}

// Custom free function
void my_free(void *ptr) {
    for (int i = 0; i < num_allocs; ++i) {
        if (allocations[i].ptr == ptr) {
            free(ptr);
            // Remove deallocated memory from tracking
            for (int j = i; j < num_allocs - 1; ++j) {
                allocations[j] = allocations[j + 1];
            }
            num_allocs--;
            return;
        }
    }
    fprintf(stderr, "Attempted to free untracked pointer\n");
}

// Function to check if all allocations are freed
void check_memory_leaks() {
    if (num_allocs == 0) {
        printf("No memory leaks detected\n");
    } else {
        printf("Memory leaks detected:\n");
        for (int i = 0; i < num_allocs; ++i) {
			dprintf(2, "Memory allocated at line %d in file %s not freed\n", allocations[i].line, allocations[i].file);
        }
    }
}


// Macros to replace malloc and free with our custom functions
#define malloc(size) my_malloc(size, __FILE__, __LINE__)
#define free(ptr) my_free(ptr)

// Example usage
int main() {
    int *ptr = malloc(sizeof(int));
    *ptr = 10;
    printf("Allocated memory at line %d in file %s\n", __LINE__ - 4, __FILE__);
    // free(ptr);
	check_memory_leaks();
    return 0;
}
