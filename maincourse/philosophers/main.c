#include "philosophers.h"

/*
	Test 1 800 200 200. The philosopher should not eat and should die.</li>
	Test 5 800 200 200. No philosopher should die.</li>
	Test 5 800 200 200 7. No philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times.
	Test 4 410 200 200. No philosopher should die.
	Test 4 310 200 100. One philosopher should die.
*/

// void start_philosopher_threads(t_simulation *sim) {
//     for (int i = 0; i < sim->shared_resources.nb_philo; i++) {
// 		// sim->shared_resources.start_time = get_current_timestamp_ms(); // this causes dataraces but i'm not sure if I get time here.
//         if (pthread_create(&sim->philosophers[i].thread, NULL, philosopher_routine, (void *)&sim->philosophers[i]) != 0) {
//             fprintf(stderr, "Error creating thread for philosopher %d\n", sim->philosophers[i].id);
//             // Handle thread creation failure (e.g., by cleaning up and exiting)
//         }
//     }
// 	// print_simulation_state(sim);
// }


void* death_monitor_routine(void* arg) {
    t_philosopher *philosopher = (t_philosopher *)arg;
    int frequency_ms = 1000; // Frequency of checks in milliseconds

    while (!philosopher->shared->someone_died) {
        usleep(frequency_ms * 1000); // Sleep for the specified interval
        check_death(philosopher); // Function to check if the philosopher has died
    }

    return NULL;
}

void start_philosopher_threads(t_simulation *sim) {
    pthread_t monitor_thread; // Declare monitor thread

    for (int i = 0; i < sim->shared_resources.nb_philo; i++) {
        if (pthread_create(&sim->philosophers[i].thread, NULL, philosopher_routine, (void *)&sim->philosophers[i]) != 0) {
            fprintf(stderr, "Error creating philosopher thread %d\n", sim->philosophers[i].id);
            // Handle error
        }
        // Create a monitor thread for each philosopher
        if (pthread_create(&monitor_thread, NULL, death_monitor_routine, (void *)&sim->philosophers[i]) != 0) {
            fprintf(stderr, "Error creating monitor thread for philosopher %d\n", sim->philosophers[i].id);
            // Handle error
        }
        // Optionally, you might want to detach the monitor thread if you don't need to join it later
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
