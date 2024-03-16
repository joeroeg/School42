#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 3

pthread_mutex_t forks[NUM_PHILOSOPHERS];

void think(int philosopher) {
    printf("Philosopher %d is thinking.\n", philosopher);
    sleep(1); // Simulate thinking
}

void eat(int philosopher) {
    printf("Philosopher %d is eating.\n", philosopher);
    sleep(2); // Simulate eating
}

void wait_for_forks(int philosopher) {
    int left = philosopher;
    int right = (philosopher + 1) % NUM_PHILOSOPHERS;

    if (philosopher == NUM_PHILOSOPHERS - 1) { // Last philosopher picks right fork first
        pthread_mutex_lock(&forks[right]);
        pthread_mutex_lock(&forks[left]);
    } else {
        pthread_mutex_lock(&forks[left]);
        pthread_mutex_lock(&forks[right]);
    }

    eat(philosopher);

    pthread_mutex_unlock(&forks[left]);
    pthread_mutex_unlock(&forks[right]);
}

void* philosopher_routine(void* arg) {
    int philosopher = *(int*)arg;
    for (int i = 0; i < 3; ++i) {
        think(philosopher);
        wait_for_forks(philosopher);
    }
    return NULL;
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_ids[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_mutex_init(&forks[i], NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher_routine, &philosopher_ids[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_join(philosophers[i], NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
