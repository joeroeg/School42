#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct ThreadData {
    int threadIndex;
} ThreadData;

void* threadFunction(void *arg) {
    ThreadData* data = (ThreadData*)arg;
    printf("Thread %d is running\n", data->threadIndex);
    free(arg); // Free the dynamically allocated memory.
    return NULL;
}

void createThreads(int numOfThreads) {
    pthread_t *threads = malloc(numOfThreads * sizeof(pthread_t));
    if (threads == NULL) {
        fprintf(stderr, "Failed to allocate memory for threads\n");
        exit(1);
    }

    for (int i = 0; i < numOfThreads; i++) {
        // Dynamically allocate memory for thread data to ensure it remains valid.
        ThreadData* data = malloc(sizeof(ThreadData));
        if (data == NULL) {
            fprintf(stderr, "Failed to allocate memory for thread data\n");
            exit(1);
        }
        data->threadIndex = i;

        if (pthread_create(&threads[i], NULL, threadFunction, data) != 0) {
            fprintf(stderr, "Failed to create thread %d\n", i);
            free(data); // Cleanup if thread creation fails.
            continue;
        }
    }

    // Wait for all threads to complete.
    for (int i = 0; i < numOfThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(threads); // Cleanup.
}

int main() {
    int numOfThreads = 5; // Example: create 5 threads.
    createThreads(numOfThreads);
    return 0;
}
