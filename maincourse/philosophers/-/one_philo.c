#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void think() {
    printf("Philosopher is thinking.\n");
    sleep(1); // Simulate thinking
}

void eat() {
    printf("Philosopher is eating.\n");
    sleep(2); // Simulate eating
}

void wait_for_forks() {
    printf("Philosopher is waiting for forks.\n");
    sleep(1); // Simulate waiting
}

void* philosopher_routine(void* arg) {
    for (int i = 0; i < 3; ++i) {
        think();
        wait_for_forks();
        eat();
    }
    return NULL;
}

int main() {
    pthread_t philosopher_thread;
    pthread_create(&philosopher_thread, NULL, philosopher_routine, NULL);
    pthread_join(philosopher_thread, NULL);
    return 0;
}
