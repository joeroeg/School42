#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

pthread_mutex_t mutexCounter;
int counter = 0;

void *incrementCounter(void *threadid) {
    long tid = (long)threadid;

    // Lock the mutex before accessing the shared counter
    pthread_mutex_lock(&mutexCounter);
    printf("Thread #%ld is incrementing the counter.\n", tid);
    counter++;
    printf("Counter value: %d\n", counter);
    // Unlock the mutex after updating the counter
    pthread_mutex_unlock(&mutexCounter);

    pthread_exit(NULL);
}

int main () {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // Initialize the mutex
    pthread_mutex_init(&mutexCounter, NULL);

    for(t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, incrementCounter, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to complete
    for(t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutexCounter);

    return 0;
}
