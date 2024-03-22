#include "philosophers.h"

/*
	run1 1 800 200 200 PASS die
	run2 5 800 200 200 FAIL no die
	run3 5 800 200 200 7 FAIL no die stop after 7 meals
	run4 4 410 200 200 PASS no die (NO SANITY CHECK)
	run5 4 310 200 100 PASS die
*/

/**
 * @todo add minimum meals to eat
 * @todo replace all forbidden functions
 * @todo limit to accept only numbers with atoi
 * @todo norminette
 * @done fix data race
 * @done handle case with 1 philosopher
*/

void *death_monitor_routine(void* arg) {
    t_philosopher *philosopher = (t_philosopher *)arg;
    int frequency_ms = 1;

    while (true) {
        ft_usleep(frequency_ms); // Wait for the specified frequency before checking again

        pthread_mutex_lock(&philosopher->shared->status_mutex);
        // Check if someone has died within the protected section
        if (philosopher->shared->someone_died) {
            pthread_mutex_unlock(&philosopher->shared->status_mutex);
            break; // Exit the loop if a death has been detected
        }
        pthread_mutex_unlock(&philosopher->shared->status_mutex);
        // Now perform the death check, since we know no one has died up until the lock was released
		pthread_mutex_lock(&philosopher->shared->satisfied_philosophers_mutex);
		int satisfied_philosophers = philosopher->shared->satisfied_philosophers;
		pthread_mutex_unlock(&philosopher->shared->satisfied_philosophers_mutex);
		if (satisfied_philosophers == philosopher->shared->nb_philo)
			break ;
		// If a death is detected, the shared variable is set within the check_death function, which should also handle locking
        if (check_death(philosopher))
            break; // Exit the loop as the simulation should stop
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
	if (sim->shared_resources.nb_philo == 1)
	{
		ft_usleep(sim->shared_resources.time_to_die);
		return ;
	}
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
	printf("-->");
    cleanup_simulation(&sim);
    return 0;
}
