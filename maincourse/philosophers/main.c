#include "philosophers.h"

void start_philosopher_threads(t_simulation *sim) {
    for (int i = 0; i < sim->shared_resources.nb_philo; i++) {
		sim->shared_resources.start_time = get_current_timestamp_ms();
        if (pthread_create(&sim->philosophers[i].thread, NULL, philosopher_routine, (void *)&sim->philosophers[i]) != 0) {
            fprintf(stderr, "Error creating thread for philosopher %d\n", sim->philosophers[i].id);
            // Handle thread creation failure (e.g., by cleaning up and exiting)
        }
    }
	// print_simulation_state(sim);
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
