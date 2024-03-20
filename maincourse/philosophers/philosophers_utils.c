#include "philosophers.h"

// Convert seconds to milliseconds and add microseconds converted to milliseconds
long long get_current_timestamp_ms() {
    struct timeval now;
    gettimeofday(&now, NULL);
    return (now.tv_sec * 1000LL) + (now.tv_usec / 1000);
}

void ft_usleep(long long time_ms, t_shared_resources *rules) {
    long long startTime = get_current_timestamp_ms();
    while (!rules->someone_died) {
        if (get_current_timestamp_ms() - startTime >= time_ms) {
            break; // Desired sleep time has elapsed
        }
        usleep(1); // Short sleep to yield CPU and check the condition frequently
    }
}

void action_print(t_philosopher *philosopher, const char *action) {
    pthread_mutex_lock(&(philosopher->shared->write_mutex));
    if (!philosopher->shared->someone_died) {
        long long current_timestamp = get_current_timestamp_ms();
        long long elapsed_time = current_timestamp - philosopher->shared->start_time;
        printf("%lld %lli %d %s\n", current_timestamp, elapsed_time, philosopher->id, action);
    }
    pthread_mutex_unlock(&(philosopher->shared->write_mutex));
}

void print_simulation_state(const t_simulation *sim) {
    if (!sim) {
        printf("Simulation pointer is NULL.\n");
        return;
    }

	printf("-----------------------------------------------------------\n");
    printf("Shared Resources:\n");
    printf("  Number of Philosophers: %d\n", sim->shared_resources.nb_philo);
    printf("  Time to Die: %d\n", sim->shared_resources.time_to_die);
    printf("  Time to Eat: %d\n", sim->shared_resources.time_to_eat);
    printf("  Time to Sleep: %d\n", sim->shared_resources.time_to_sleep);
    printf("  Time to Think: %d\n", sim->shared_resources.time_to_think);
    printf("  Max Meals: %d\n", sim->shared_resources.max_meals);
    printf("  Start Time: %lld\n", sim->shared_resources.start_time);
    printf("  All Ate: %d\n", sim->shared_resources.all_ate);
    printf("  Someone Died: %d\n", sim->shared_resources.someone_died);
    // Note: Mutexes are not printed as their state isn't easily represented in a simple printout

    printf("\nPhilosophers:\n");
    for (int i = 0; i < sim->shared_resources.nb_philo; i++) {
        printf("  Philosopher %d:\n", sim->philosophers[i].id);
        printf("    Meals Eaten: %d\n", sim->philosophers[i].meals_eaten);
        printf("    Last Meal Time: %lld\n", sim->philosophers[i].last_meal_time);
        // Not printing the 'shared' pointer as it points to the shared_resources already printed
        // Not printing the thread ID as it's not easily represented in a printout
    }
	printf("-----------------------------------------------------------\n");
}
