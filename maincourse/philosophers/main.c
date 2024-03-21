#include "philosophers.h"

/*
	Test 1 800 200 200. The philosopher should not eat and should die.
	Test 5 800 200 200. No philosopher should die.
	Test 5 800 200 200 7. No philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times.
	Test 4 410 200 200. No philosopher should die.
	Test 4 310 200 100. One philosopher should die.
*/

/**
 * @done fix data race
 * @todo add minimum meals to eat
 * @todo handle case with 1 philosopher
 * @todo replace all forbidden functions
 * @todo limit to accept only numbers with atoi
 * @todo norminette
*/

void *death_monitor_routine(void* arg) {
    t_philosopher *philosopher = (t_philosopher *)arg;
    int frequency_ms = 1;

    while (true) {
        usleep(frequency_ms * 1000); // Wait for the specified frequency before checking again

        pthread_mutex_lock(&philosopher->shared->status_mutex);
        // Check if someone has died within the protected section
        if (philosopher->shared->someone_died) {
            pthread_mutex_unlock(&philosopher->shared->status_mutex);
            break; // Exit the loop if a death has been detected
        }
        pthread_mutex_unlock(&philosopher->shared->status_mutex);

        // Now perform the death check, since we know no one has died up until the lock was released
        if (check_death(philosopher)) {
            // If a death is detected, the shared variable is set within the check_death function, which should also handle locking
            break; // Exit the loop as the simulation should stop
        }
    }
    return NULL;
}


void start_philosopher_threads(t_simulation *sim) {
    pthread_t monitor_thread;

    for (int i = 0; i < sim->shared_resources.nb_philo; i++) {
        if (pthread_create(&sim->philosophers[i].thread, NULL, philosopher_routine, (void *)&sim->philosophers[i]) != 0) {
            fprintf(stderr, "Error creating philosopher thread %d\n", sim->philosophers[i].id);
        }
        if (pthread_create(&monitor_thread, NULL, death_monitor_routine, (void *)&sim->philosophers[i]) != 0) {
            fprintf(stderr, "Error creating monitor thread for philosopher %d\n", sim->philosophers[i].id);
        }
        pthread_detach(monitor_thread);
    }
}

void join_philosopher_threads(t_simulation *sim) {
    for (int i = 0; i < sim->shared_resources.nb_philo; i++) {
        pthread_join(sim->philosophers[i].thread, NULL);
    }
}

int main(int argc, char **argv)
{
    t_simulation	sim;

    if (argc < 5 || argc > 6)
	{
        fprintf(stderr, "Usage: %s <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [max_meals]\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (init_simulation(argc, argv, &sim) != 0) {
        fprintf(stderr, "Failed to initialize simulation.\n");
        return EXIT_FAILURE;
    }
	print_simulation_state(&sim);
	start_philosopher_threads(&sim);
    join_philosopher_threads(&sim);
    cleanup_simulation(&sim);
    return 0;
}
