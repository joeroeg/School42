#ifndef PHILOSOPHERS
#define PHILOSOPHERS_H
#endif

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct {
    pthread_mutex_t* forks;
} DiningTable;

typedef struct {
	int num_philosophers;
    int philosopher_id;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int times_to_eat;
	DiningTable* table;
} philosopher_args;

void *philosopher_routine(void *arg);
void *eating(void *arg);
void *sleeping(void *arg);
void *thinking(void *arg);
void wait_for_forks(philosopher_args* args);
