#include "philosophers.h"

void *eating(void *arg)
{
    philosopher_args *philosopher = (philosopher_args *)arg;
    printf("Philosopher %d is eating\n", philosopher->philosopher_id);
    usleep(philosopher->time_to_eat); // Assuming time_to_eat is in milliseconds
    return NULL;
}

void *thinking(void *arg)
{
    philosopher_args *philosopher = (philosopher_args *)arg;
    printf("Philosopher %d is thinking\n", philosopher->philosopher_id);
    usleep(philosopher->time_to_sleep);
    return NULL;
}

void *sleeping(void *arg)
{
    philosopher_args *philosopher = (philosopher_args *)arg;
    printf("Philosopher %d is sleeping\n", philosopher->philosopher_id);
    usleep(philosopher->time_to_sleep);
    return NULL;
}

void* philosopher_routine(void* arg) {
    philosopher_args* args = (philosopher_args*)arg;

    for (int i = 0; i < 3; ++i) {
        thinking(&args->philosopher_id);
        wait_for_forks(args);
    }
    return NULL;
}

