#include "philosophers.h"

void cleanup_simulation(t_simulation *sim) {
    if (!sim) return; // Safety check to ensure we have a valid pointer

    // Destroy the mutexes for writing and status checking
	pthread_mutex_destroy(&sim->shared_resources.write_mutex);
	pthread_mutex_destroy(&sim->shared_resources.status_mutex);
	pthread_mutex_destroy(&sim->shared_resources.last_meal_time_mutex);
	// pthread_mutex_destroy(&sim->shared_resources.meal_mutex); // Illegal instruction: 4 | when make run1
	pthread_mutex_destroy(&sim->shared_resources.satisfied_philosophers_mutex);



    // Destroy the mutexes for each fork
    for (int i = 0; i < sim->shared_resources.nb_philo; i++) {
        pthread_mutex_destroy(&sim->shared_resources.forks[i]);
    }

    // Additional cleanup tasks can be added here.
    // For example, if you dynamically allocate memory for philosophers
    // or other parts of the simulation, you would free that memory here.

    // Note: There's no need to explicitly clean up the philosopher threads
    // (with pthread_join or similar) here, as that should be done before
    // calling this cleanup function to ensure all threads have finished execution.
}

int validate_simulation_params(int argc, char **argv) {
    int nb_philo = ft_atoi(argv[1]);
    int time_to_die = ft_atoi(argv[2]);
    int time_to_eat = ft_atoi(argv[3]);
    int time_to_sleep = ft_atoi(argv[4]);
	int max_meals;
	if (argc == 6)
		max_meals = ft_atoi(argv[5]);
	else
		max_meals = -1;
    if (nb_philo <= 0 || nb_philo > MAX_PHILOSOPHERS ||
        time_to_die <= 0 || time_to_eat <= 0 || time_to_sleep <= 0 ||
        (argc == 6 && max_meals < 0)) {
		write(2, "Invalid simulation configuration. All parameters must be positive integers.\n", 70);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int init_simulation_mutexes(t_simulation *sim)
{
    if ((pthread_mutex_init(&sim->shared_resources.write_mutex, NULL) != 0 ||
		pthread_mutex_init(&sim->shared_resources.status_mutex, NULL) != 0) ||
		pthread_mutex_init(&sim->shared_resources.last_meal_time_mutex, NULL) != 0 ||
		pthread_mutex_init(&sim->shared_resources.satisfied_philosophers_mutex, NULL) != 0)
	{
		write(2, "Failed to initialize control mutexes.\n", 38);
        return -1;
    }

    for (int i = 0; i < sim->shared_resources.nb_philo; i++) {
        if (pthread_mutex_init(&sim->shared_resources.forks[i], NULL) != 0) {
			write(2, "Failed to initialize fork mutex.\n", 34);
            // Cleanup already initialized mutexes
            cleanup_simulation(sim); // Assume this function can handle partial cleanup
            return -1;
        }
    }
    return EXIT_SUCCESS;
}

int init_philosophers(t_simulation *sim) {
    if (!sim || sim->shared_resources.nb_philo <= 0) {
		write(2, "Invalid simulation or configuration.\n", 37);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < sim->shared_resources.nb_philo; i++) {
        sim->philosophers[i].id = i + 1;
        sim->philosophers[i].meals_eaten = 0;
        sim->philosophers[i].last_meal_time = 0;
        sim->philosophers[i].shared = &sim->shared_resources;
    }
    return EXIT_SUCCESS;
}

int init_simulation(int argc, char **argv, t_simulation *sim) {
    if (validate_simulation_params(argc, argv) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    // Capture the start time at the beginning of the simulation
    long long start_time = get_current_timestamp_ms(); // @changes 001 I want to start_time before first thread
    sim->shared_resources.start_time = start_time;

    // Set simulation parameters
    sim->shared_resources.nb_philo = ft_atoi(argv[1]);
    sim->shared_resources.time_to_die = ft_atoi(argv[2]);
    sim->shared_resources.time_to_eat = ft_atoi(argv[3]);
    sim->shared_resources.time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6) {
        sim->shared_resources.max_meals = ft_atoi(argv[5]);
    } else {
        sim->shared_resources.max_meals = -1;
    }
	sim->shared_resources.satisfied_philosophers = 0;
    sim->shared_resources.all_ate = 0;
    sim->shared_resources.someone_died = 0;
    // sim->shared_resources.time_to_think = 0; // Assuming this is intentional

    // Initialize mutexes
    if (init_simulation_mutexes(sim) != EXIT_SUCCESS) {
		write(2, "Failed to initialize mutexes.\n", 31);
        return EXIT_FAILURE;
    }

    // Initialize philosophers and set their last_meal_time to start_time
    if (init_philosophers(sim) != EXIT_SUCCESS) {
		write(2, "Failed to initialize philosophers.\n", 36);
        cleanup_simulation(sim);
        return EXIT_FAILURE;
    }

    // Update to set each philosopher's last_meal_time to the start time of the simulation
    for (int i = 0; i < sim->shared_resources.nb_philo; i++) {
        sim->philosophers[i].last_meal_time = start_time;
    }

    return EXIT_SUCCESS;
}

