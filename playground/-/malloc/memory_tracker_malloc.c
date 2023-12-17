#include <stdlib.h>
#include <stdio.h>

#define CUSTOM_MALLOC(tracker, size) custom_malloc(tracker, size, __FILE__, __LINE__)

typedef struct Node {
    void *memory;           // Pointer to the allocated memory
    size_t size;            // Size of the memory block
    const char *file;       // File where the allocation was made
    int line;               // Line number of the allocation
    struct Node *next;      // Pointer to the next node
} Node;

typedef struct {
    Node *head;             // Head of the linked list
} MemoryTracker;

MemoryTracker *createMemoryTracker() {
    MemoryTracker *tracker = (MemoryTracker *)malloc(sizeof(MemoryTracker));
    if (tracker) {
        tracker->head = NULL;
    }
    return tracker;
}

// Updated function to add a node to the tracker's linked list
void addNode(MemoryTracker *tracker, void *memory, size_t size, const char *file, int line) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        // Handle memory allocation failure for the new node
        return;
    }

    newNode->memory = memory;
    newNode->size = size;
    newNode->file = file;
    newNode->line = line;
    newNode->next = tracker->head;
    tracker->head = newNode;
}


// Updated function to remove a node from the tracker's linked list
void removeNode(MemoryTracker *tracker, void *memory) {
    Node *current = tracker->head;
    Node *prev = NULL;

    while (current != NULL) {
        if (current->memory == memory) {
            if (prev == NULL) {
                tracker->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void *custom_malloc(MemoryTracker *tracker, size_t size, const char *file, int line) {
    void *memory = malloc(size);
    if (memory) {
        addNode(tracker, memory, size, file, line);
    }
    return memory;
}

void custom_free(MemoryTracker *tracker, void *memory) {
    if (memory) {
        removeNode(tracker, memory); // Use removeNode function
        free(memory); // Free the actual memory allocated
    }
}

// Additional function to clean up the memory tracker
void cleanupMemoryTracker(MemoryTracker *tracker) {
    Node *current = tracker->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp->memory); // Free the allocated memory
        free(temp); // Free the node
    }
    free(tracker); // Free the memory tracker itself
}

int main() {
    MemoryTracker *tracker = createMemoryTracker();

    // Allocate memory using the enhanced malloc
    int *data1 = (int *)CUSTOM_MALLOC(tracker, sizeof(int) * 10);
    int *data2 = (int *)CUSTOM_MALLOC(tracker, sizeof(int) * 20); // This will be leaked
    int *data3 = (int *)CUSTOM_MALLOC(tracker, sizeof(int) * 5);

    // Free only some of the allocated memory
    custom_free(tracker, data1);
    custom_free(tracker, data3);
    // 'data2' is not freed - memory leak!

    // Identify the memory leak with file and line information
    Node *current = tracker->head;
    while (current != NULL) {
        printf("Leaked Memory: Address=%p, Size=%zu bytes, File: %s, Line: %d\n",
               current->memory, current->size, current->file, current->line);
        current = current->next;
    }

    // Clean up tracker and remaining allocations
    cleanupMemoryTracker(tracker);

    return 0;
}


