#include "philosophers.h"

void initialize_struct(int argc, char **argv, philosopher_args philosopher)
{
	philosopher.philosopher_id = atoi(argv[1]);
	philosopher.time_to_die = atoi(argv[2]) * 1000;
	philosopher.time_to_eat = atoi(argv[3]) * 1000;
	philosopher.time_to_sleep = atoi(argv[4]) * 1000;
	if (argc == 6)
		philosopher.times_to_eat = atoi(argv[5]);
	else
		philosopher.times_to_eat = -1;
	// printf("philosopher_id: %d\n", philosopher.philosopher_id);
	// printf("time_to_die: %d\n", philosopher.time_to_die);
	// printf("time_to_eat: %d\n", philosopher.time_to_eat);
	// printf("time_to_sleep: %d\n", philosopher.time_to_sleep);
}

void wait_for_forks(philosopher_args* args) {
    int philosopher = args->philosopher_id;
    int num_philosophers = args->num_philosophers;
    DiningTable* table = args->table;
    int left = philosopher;
    int right = (philosopher + 1) % num_philosophers;

    if (philosopher == num_philosophers - 1) { // Last philosopher picks right fork first
        pthread_mutex_lock(&table->forks[right]);
        pthread_mutex_lock(&table->forks[left]);
    } else {
        pthread_mutex_lock(&table->forks[left]);
        pthread_mutex_lock(&table->forks[right]);
    }

    eating(args);

    pthread_mutex_unlock(&table->forks[left]);
    pthread_mutex_unlock(&table->forks[right]);
}


void create_threads(int num_philosophers) {
    pthread_t *threads = malloc(num_philosophers * sizeof(pthread_t));
    if (threads == NULL) {
        fprintf(stderr, "Failed to allocate memory for threads\n");
        exit(1);
    }

    for (int i = 0; i < num_philosophers; i++) {
        // Dynamically allocate memory for thread data to ensure it remains valid.
        philosopher_args* data = malloc(sizeof(philosopher_args));
        if (data == NULL) {
            fprintf(stderr, "Failed to allocate memory for thread data\n");
            exit(1);
        }
        data->philosopher_id = i;

        if (pthread_create(&threads[i], NULL, philosopher_routine, data) != 0) {
            fprintf(stderr, "Failed to create thread %d\n", i);
            free(data); // Cleanup if thread creation fails.
            continue;
        }
    }

    // Wait for all threads to complete.
    for (int i = 0; i < num_philosophers; i++) {
        pthread_join(threads[i], NULL);
    }

    free(threads); // Cleanup.
}

int main(int argc, char **argv)
{
	philosopher_args *philosopher = malloc(sizeof(philosopher_args));
	initialize_struct(argc, argv, *philosopher);
	create_threads(philosopher->philosopher_id);
	free(philosopher);
	return 0;
}
