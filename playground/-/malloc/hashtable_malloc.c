#include <stdlib.h>
#include <stdio.h>

#define TABLE_SIZE 1024  // Size of the hashtable

typedef struct AllocationInfo {
    void *ptr;              // Pointer to the allocated memory
    size_t size;            // Size of the memory block
} AllocationInfo;

typedef struct HashNode {
    AllocationInfo info;    // Information about the allocation
    struct HashNode *next;  // Pointer to the next node (for collision resolution)
} HashNode;

typedef struct {
    HashNode *buckets[TABLE_SIZE]; // Array of pointers to hash nodes
} HashTable;


unsigned int hash(void *ptr) {
    return ((unsigned long)ptr) % TABLE_SIZE;
}


void hashTableInsert(HashTable *table, void *ptr, size_t size) {
    unsigned int bucket = hash(ptr);
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->info.ptr = ptr;
    newNode->info.size = size;
    newNode->next = table->buckets[bucket];
    table->buckets[bucket] = newNode;
}


void hashTableRemove(HashTable *table, void *ptr) {
    unsigned int bucket = hash(ptr);
    HashNode *current = table->buckets[bucket];
    HashNode *prev = NULL;
    while (current != NULL) {
        if (current->info.ptr == ptr) {
            if (prev == NULL) {
                table->buckets[bucket] = current->next;
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

void *custom_malloc(HashTable *table, size_t size) {
    void *ptr = malloc(size);
    if (ptr) {
        hashTableInsert(table, ptr, size);
    }
    return ptr;
}


void custom_free(HashTable *table, void *ptr) {
    if (ptr) {
        hashTableRemove(table, ptr);
        free(ptr);
    }
}

// Initialize HashTable
HashTable *createHashTable() {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    if (table) {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table->buckets[i] = NULL;
        }
    }
    return table;
}


void cleanupHashTable(HashTable *table) {
    if (table == NULL) {
        return;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode *current = table->buckets[i];
        while (current != NULL) {
            // Report the unfreed memory allocation
            printf("Leaked Memory: Address=%p, Size=%zu bytes\n", current->info.ptr, current->info.size);

            // Free the memory allocation if you want to clean up all memory
            // free(current->info.ptr);

            HashNode *temp = current;
            current = current->next;
            free(temp);
        }
    }

    // Finally, free the hashtable itself
    free(table);
}


int main() {
    HashTable *table = createHashTable();

    // Allocate memory multiple times
    int *data1 = (int *)custom_malloc(table, sizeof(int) * 10);
    int *data2 = (int *)custom_malloc(table, sizeof(int) * 20); // This will be leaked
    int *data3 = (int *)custom_malloc(table, sizeof(int) * 5);

    // Free only some of the allocated memory
    custom_free(table, data1);
    custom_free(table, data3);
    // 'data2' is not freed - memory leak!

    // Before exiting the program, clean up the hashtable and check for leaks
    cleanupHashTable(table);

    return 0;
}

