#include "philosophers.h"

/*
	run1 1 800 200 200 PASS die
	run2 5 800 200 200 PASS no die
	run3 5 800 200 200 7 PASS no die stop after 7 meals
	run4 4 410 200 200 PASS no die (NO SANITY CHECK)
	run5 4 310 200 100 PASS die
*/

/**
 * @todo replace all forbidden functions
 * @todo destroy mutexes
 * @todo check memory leaks
 * @todo Think of how to stop simulation after all philosophers have eaten minimum meals
 * @todo norminette
 * @done limit to accept only numbers with atoi
 * @done add minimum meals to eat
 * @done fix data race
 * @done handle case with 1 philosopher
*/

void *death_monitor_routine(void* arg) {
    t_philosopher *philosopher = (t_philosopher *)arg;
    int frequency_ms = 1;

    while (true) {
        ft_usleep(frequency_ms);

        pthread_mutex_lock(&philosopher->shared->status_mutex);
        if (philosopher->shared->someone_died) {
            pthread_mutex_unlock(&philosopher->shared->status_mutex);
            break ;
        }
        pthread_mutex_unlock(&philosopher->shared->status_mutex);
		pthread_mutex_lock(&philosopher->shared->satisfied_philosophers_mutex);
		if (philosopher->shared->satisfied_philosophers == philosopher->shared->nb_philo)
		{
			pthread_mutex_unlock(&philosopher->shared->satisfied_philosophers_mutex);
			break ;
		}
		pthread_mutex_unlock(&philosopher->shared->satisfied_philosophers_mutex);
        if (check_death(philosopher))
            break ;
    }
    return NULL;
}


void start_philosopher_threads(t_simulation *sim) {
    pthread_t monitor_thread;

    for (int i = 0; i < sim->shared_resources.nb_philo; i++) {
        if (pthread_create(&sim->philosophers[i].thread, NULL, philosopher_routine, (void *)&sim->philosophers[i]) != 0) {
			write(2, "Error creating philosopher thread\n", 35);
        }
        if (pthread_create(&monitor_thread, NULL, death_monitor_routine, (void *)&sim->philosophers[i]) != 0) {
			write(2, "Error creating monitor thread\n", 31);
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
		write(2, "Error: Invalid number of arguments\n", 36);
        return EXIT_FAILURE;
    }
    if (init_simulation(argc, argv, &sim) != 0) {
		write(2, "Failed to initialize simulation.\n", 34);
        return EXIT_FAILURE;
    }
	print_simulation_state(&sim);
	start_philosopher_threads(&sim);
    join_philosopher_threads(&sim);
    cleanup_simulation(&sim);
    return EXIT_SUCCESS;
}
