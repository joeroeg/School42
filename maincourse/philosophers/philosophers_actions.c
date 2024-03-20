#include "philosophers.h"

// time_to_think is initialized to 0 and not passed as an argument.
void thinking(t_philosopher *philosopher) {
    action_print(philosopher, "is thinking");
    // ft_usleep(philosopher->shared->time_to_think, philosopher->shared);
}

void eating(t_philosopher *philosopher) {
    // action_print(philosopher, "is eating");
    ft_usleep(philosopher->shared->time_to_eat, philosopher->shared);
    philosopher->last_meal_time = get_current_timestamp_ms(); // Update time after eating
}

void sleeping(t_philosopher *philosopher) {
    // action_print(philosopher, "is sleeping");
    ft_usleep(philosopher->shared->time_to_sleep, philosopher->shared);
}

void pick_up_forks(t_philosopher *philosopher) {
    int left_fork = philosopher->id - 1; // Assuming ID starts from 1
    int right_fork = philosopher->id % philosopher->shared->nb_philo; // Wrap around for the last philosopher

    if (philosopher->id % 2 == 0) {
        // Even ID philosophers pick up the right fork first
        pthread_mutex_lock(&(philosopher->shared->forks[right_fork]));
        action_print(philosopher, "has taken a fork");

        pthread_mutex_lock(&(philosopher->shared->forks[left_fork]));
        action_print(philosopher, "has taken a fork");
    } else {
        // Odd ID philosophers pick up the left fork first
        pthread_mutex_lock(&(philosopher->shared->forks[left_fork]));
        action_print(philosopher, "has taken a fork");

        pthread_mutex_lock(&(philosopher->shared->forks[right_fork]));
        action_print(philosopher, "has taken a fork");
    }
}

void put_down_forks(t_philosopher *philosopher) {
    int left = philosopher->id - 1; // Assuming ID starts from 1
    int right = philosopher->id % philosopher->shared->nb_philo; // Wrap around for the last philosopher
    pthread_mutex_unlock(&philosopher->shared->forks[left]);
    pthread_mutex_unlock(&philosopher->shared->forks[right]);
}

void signal_stop(t_shared_resources *shared) {
    pthread_mutex_lock(&shared->write_mutex); // Use the mutex if accessing shared state variables
    shared->someone_died = 1;
    pthread_mutex_unlock(&shared->write_mutex);
}

void check_death(t_philosopher *philosopher) {
    long long current_time = get_current_timestamp_ms();
    long long time_since_last_meal = current_time - philosopher->last_meal_time;

    if (time_since_last_meal >= philosopher->shared->time_to_die) {
        pthread_mutex_lock(&philosopher->shared->write_mutex);
		// printf("   Current Timestamp: %lld\n", get_current_timestamp_ms());
		// printf("        current_time: %lld\n", current_time);
		// printf("      last_meal_time: %lld\n", philosopher->last_meal_time);
		// printf("time_since_last_meal: %lld\n", time_since_last_meal);
		// printf("         time_to_die: %d\n", philosopher->shared->time_to_die);
        // printf("%lld %d has died\n", current_time - philosopher->shared->start_time, philosopher->id);
        philosopher->shared->someone_died = 1;
        pthread_mutex_unlock(&philosopher->shared->write_mutex);

        // Optionally signal all threads to stop
		// signal_stop(philosopher->shared);
    }
}

void *philosopher_routine(void *arg) {
    t_philosopher *philosopher = (t_philosopher *)arg;

    while (!philosopher->shared->someone_died) {
        pick_up_forks(philosopher);

        // // Before eating, check if this philosopher has already died due to starvation
        // check_death(philosopher);
        // if (philosopher->shared->someone_died) {
        //     put_down_forks(philosopher); // Ensure to release any resources if stopping early
        //     break;
        // }
        eating(philosopher);
        put_down_forks(philosopher);
        sleeping(philosopher);
        // thinking(philosopher);
        // check_death(philosopher);
    }

    return NULL;
}


