#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 3

typedef struct {
    int num_philosophers;
    pthread_mutex_t* forks;
    int* philosopher_ids; // To identify each philosopher
} DiningTable;

void think(int philosopher) {
    printf("Philosopher %d is thinking.\n", philosopher);
    sleep(1); // Simulate thinking
}

void eat(int philosopher) {
    printf("Philosopher %d is eating.\n", philosopher);
    sleep(2); // Simulate eating
}

void wait_for_forks(DiningTable* table, int philosopher) {
    int left = philosopher;
    int right = (philosopher + 1) % table->num_philosophers;

    if (philosopher == table->num_philosophers - 1) { // Last philosopher picks right fork first
        pthread_mutex_lock(&table->forks[right]);
        pthread_mutex_lock(&table->forks[left]);
    } else {
        pthread_mutex_lock(&table->forks[left]);
        pthread_mutex_lock(&table->forks[right]);
    }

    eat(philosopher);

    pthread_mutex_unlock(&table->forks[left]);
    pthread_mutex_unlock(&table->forks[right]);
}

void* philosopher_routine(void* arg) {
    int philosopher = *(int*)arg;
    DiningTable* table = (DiningTable*)((int*)arg + 1); // Adjust pointer to access the dining table

    for (int i = 0; i < 3; ++i) {
        think(philosopher);
        wait_for_forks(table, philosopher);
    }
    return NULL;
}

DiningTable* init_dining_table(int num_philosophers) {
    DiningTable* table = malloc(sizeof(DiningTable));
    table->num_philosophers = num_philosophers;
    table->forks = malloc(num_philosophers * sizeof(pthread_mutex_t));
    table->philosopher_ids = malloc(num_philosophers * sizeof(int));

    for (int i = 0; i < num_philosophers; ++i) {
        pthread_mutex_init(&table->forks[i], NULL);
        table->philosopher_ids[i] = i;
    }
    return table;
}

int main() {
    int num_philosophers = NUM_PHILOSOPHERS;
    DiningTable* table = init_dining_table(num_philosophers);
    pthread_t philosophers[num_philosophers];
    int args[num_philosophers][2]; // To pass both philosopher ID and pointer to the table

    for (int i = 0; i < num_philosophers; ++i) {
        args[i][0] = i;
        *((DiningTable**)(args[i] + 1)) = table; // Store the table pointer right after the ID
        pthread_create(&philosophers[i], NULL, philosopher_routine, args[i]);
    }

    for (int i = 0; i < num_philosophers; ++i) {
        pthread_join(philosophers[i], NULL);
    }

    // Cleanup
    for (int i = 0; i < num_philosophers; ++i) {
        pthread_mutex_destroy(&table->forks[i]);
    }
    free(table->forks);
    free(table->philosopher_ids);
    free(table);
    return 0;
}
