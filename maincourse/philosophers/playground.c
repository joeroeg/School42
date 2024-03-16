#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

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
	long long first_timestamp;
	long long last_meal_time;
	pthread_mutex_t writing;
	pthread_mutex_t last_meal_mutex;
	int dieded;
	DiningTable* table;
} philosopher_args;

void action_print(philosopher_args *philosopher, int id, char *string) {
    pthread_mutex_lock(&(philosopher->writing));
    if (!philosopher->dieded) {
        struct timeval now;
        gettimeofday(&now, NULL);
        long long current_timestamp = (now.tv_sec * 1000) + (now.tv_usec / 1000);
        long long elapsed_time = current_timestamp - philosopher->first_timestamp;
        printf("%lli %i %s\n", elapsed_time, id + 1, string);
    }
    pthread_mutex_unlock(&(philosopher->writing));
}

void *eating(void *arg) {
    philosopher_args *philosopher = (philosopher_args *)arg;
    action_print(philosopher, philosopher->philosopher_id, "is eating");
    usleep(philosopher->time_to_eat); // Simulate eating

    struct timeval now;
    gettimeofday(&now, NULL);

    pthread_mutex_lock(&(philosopher->last_meal_mutex));
    philosopher->last_meal_time = (now.tv_sec * 1000) + (now.tv_usec / 1000);
    pthread_mutex_unlock(&(philosopher->last_meal_mutex));

    return NULL;
}



void *thinking(void *arg)
{
    philosopher_args *philosopher = (philosopher_args *)arg;
	action_print(philosopher, philosopher->philosopher_id, "is thinking");
    usleep(philosopher->time_to_sleep);
    return NULL;
}

void *sleeping(void *arg)
{
    philosopher_args *philosopher = (philosopher_args *)arg;
	action_print(philosopher, philosopher->philosopher_id, "is sleeping");
    usleep(philosopher->time_to_sleep);
    return NULL;
}

philosopher_args *initialize_struct(int argc, char **argv)
{
	philosopher_args *philosopher = malloc(sizeof(philosopher_args));
	philosopher->num_philosophers = atoi(argv[1]);
	philosopher->time_to_die = atoi(argv[2]) * 1000;
	philosopher->time_to_eat = atoi(argv[3]) * 1000;
	philosopher->time_to_sleep = atoi(argv[4]) * 1000;
	if (argc == 6)
		philosopher->times_to_eat = atoi(argv[5]);
	else
		philosopher->times_to_eat = -1;
	return (philosopher);
}

void wait_for_forks(philosopher_args* args) {
    int philosopher = args->philosopher_id;
    int num_philosophers = args->num_philosophers;
    DiningTable* table = args->table;
    int left = philosopher - 1;
    int right = philosopher % num_philosophers;

    if (philosopher == num_philosophers - 1) { // Last philosopher picks right fork first
        pthread_mutex_lock(&table->forks[right]);
		action_print(args, args->philosopher_id, "has taken a fork");
        pthread_mutex_lock(&table->forks[left]);
		action_print(args, args->philosopher_id, "has taken a fork");
    } else {
        pthread_mutex_lock(&table->forks[left]);
		action_print(args, args->philosopher_id, "has taken a fork");
        pthread_mutex_lock(&table->forks[right]);
		action_print(args, args->philosopher_id, "has taken a fork");
    }

    eating(args);

    pthread_mutex_unlock(&table->forks[left]);
    pthread_mutex_unlock(&table->forks[right]);
}


int check_survival(philosopher_args* philosopher) {
    struct timeval now;
    gettimeofday(&now, NULL);
    long long current_time = (now.tv_sec * 1000) + (now.tv_usec / 1000);
    long long time_since_last_meal = current_time - philosopher->last_meal_time;

    // Check if the philosopher has survived
    if (time_since_last_meal > philosopher->time_to_die) {
        // Philosopher has not survived
        action_print(philosopher, philosopher->philosopher_id, "has died");
        return 0; // Indicate death
    }
    return 1; // Philosopher is still alive
}

void *philosopher_routine(void* arg) {
    philosopher_args* args = (philosopher_args*)arg;

    // Initialize last meal time at the start to ensure no false positives for death
    struct timeval now;
    gettimeofday(&now, NULL);
    args->last_meal_time = (now.tv_sec * 1000) + (now.tv_usec / 1000);

    while (1) {
        if (!check_survival(args)) {
            break; // Exit loop if philosopher didn't survive
        }

        wait_for_forks(args); // Attempt to eat
        if (!check_survival(args)) {
            // Additional check after eating attempt in case philosopher couldn't eat in time
            break;
        }

        sleeping(args);
        thinking(args);
    }

    return NULL;
}


void initialize_rules(philosopher_args *philosopher_args) {
    struct timeval start;
    gettimeofday(&start, NULL);
    philosopher_args->first_timestamp = (start.tv_sec * 1000) + (start.tv_usec / 1000);
    pthread_mutex_init(&(philosopher_args->writing), NULL);
	pthread_mutex_init(&(philosopher_args->last_meal_mutex), NULL);
    philosopher_args->dieded = 0;
}


void create_threads(philosopher_args *philosopher) {
    pthread_t *threads = malloc(philosopher->num_philosophers * sizeof(pthread_t));
    philosopher_args **dataPointers = malloc(philosopher->num_philosophers * sizeof(philosopher_args*));

    if (threads == NULL || dataPointers == NULL) {
        fprintf(stderr, "Failed to allocate memory for threads or philosopher args pointers\n");
        // Free whichever was successfully allocated before exiting
        if (threads != NULL) free(threads);
        if (dataPointers != NULL) free(dataPointers);
        exit(1);
    }

	initialize_rules(philosopher);
    for (int i = 0; i < philosopher->num_philosophers; i++) {
        philosopher_args *data = malloc(sizeof(philosopher_args));
        if (data == NULL) {
            fprintf(stderr, "Failed to allocate memory for thread data\n");
            exit(1);
        }
        *data = *philosopher;
        data->philosopher_id = i + 1; // Adjusted to be zero-index safe

        dataPointers[i] = data; // Store the pointer to free later

        if (pthread_create(&threads[i], NULL, philosopher_routine, data) != 0) {
            fprintf(stderr, "Failed to create thread %d\n", i + 1);
            free(data); // Cleanup immediately if thread creation fails
            continue;
        }
    }

    // Wait for all threads to complete and free their philosopher_args
    for (int i = 0; i < philosopher->num_philosophers; i++) {
        pthread_join(threads[i], NULL);
        free(dataPointers[i]); // Free the memory allocated for the philosopher's arguments
    }
    free(dataPointers); // Finally, free the array of pointers itself
    free(threads); // Cleanup
}

void initialize_dining_table(philosopher_args *philosopher) {
	philosopher->table = malloc(sizeof(DiningTable));
    philosopher->table->forks = malloc(philosopher->num_philosophers * sizeof(pthread_mutex_t));
    for (int i = 0; i < philosopher->num_philosophers; ++i) {
        pthread_mutex_init(&philosopher->table->forks[i], NULL);
    }
}

int main(int argc, char **argv)
{
	if (argc < 5) {
        fprintf(stderr, "Usage: %s <num_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [times_to_eat]\n", argv[0]);
        return 1;
    }
	philosopher_args *philosopher = initialize_struct(argc, argv);
	initialize_dining_table(philosopher);
	create_threads(philosopher);
	free(philosopher->table->forks);
	free(philosopher->table);
	free(philosopher);
	return 0;
}
