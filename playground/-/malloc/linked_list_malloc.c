#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    void *memory;        // Pointer to the allocated memory
    size_t size;         // Size of the memory block
    struct Node *next;   // Pointer to the next node
} Node;

typedef struct {
    Node *head;          // Head of the linked list
} MemoryTracker;


MemoryTracker *createMemoryTracker() {
    MemoryTracker *tracker = (MemoryTracker *)malloc(sizeof(MemoryTracker));
    if (tracker) {
        tracker->head = NULL;
    }
    return tracker;
}


void addNode(void *memory, size_t size) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        // Handle memory allocation failure for the new node
        return;
    }

    newNode->memory = memory;
    newNode->size = size;
    newNode->next = head;
    head = newNode;
}

void removeNode(void *memory) {
    Node *current = head;
    Node *prev = NULL;

    while (current != NULL) {
        if (current->memory == memory) {
            if (prev == NULL) {
                head = current->next;
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

void *custom_malloc(MemoryTracker *tracker, size_t size) {
    void *memory = malloc(size);
    if (memory) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->memory = memory;
        newNode->size = size;
        newNode->next = tracker->head;
        tracker->head = newNode;
    }
    return memory;
}



void custom_free(MemoryTracker *tracker, void *memory) {
    Node *current = tracker->head;
    Node *prev = NULL;

    while (current != NULL) {
        if (current->memory == memory) {
            if (prev == NULL) {
                tracker->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->memory);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}


