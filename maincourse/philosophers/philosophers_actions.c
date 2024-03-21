#include "philosophers.h"

void print_philosopher(const t_philosopher *philosopher) {
    printf("      \033[0;32mPhilosopher ID: %d\033[0m\n", philosopher->id);
    printf("         \033[0;32mMeals Eaten: %d\033[0m\n", philosopher->meals_eaten);
    printf("      \033[0;32mLast Meal Time: %lld\033[0m\n", philosopher->last_meal_time % MULTIPLIER);
	printf("\033[0;32mExpected Time to Die: %lld\033[0m\n", (philosopher->last_meal_time + philosopher->shared->time_to_die) % MULTIPLIER);    // Assuming t_shared_resources is defined elsewhere, you can print its members accordingly
	printf("   \033[0;32mCurrent Timestamp: %lld\033[0m\n", get_current_timestamp_ms() %MULTIPLIER);
}

// time_to_think is initialized to 0 and not passed as an argument.
void thinking(t_philosopher *philosopher) {
    action_print(philosopher, "is thinking");
    // ft_usleep(philosopher->shared->time_to_think, philosopher->shared);
}

void eating(t_philosopher *philosopher) {
    action_print(philosopher, "is eating");
    ft_usleep(philosopher->shared->time_to_eat, philosopher->shared);
    philosopher->last_meal_time = get_current_timestamp_ms(); // Update time after eating
	print_philosopher(philosopher);
}

void sleeping(t_philosopher *philosopher) {
    action_print(philosopher, "is sleeping");
    ft_usleep(philosopher->shared->time_to_sleep, philosopher->shared);
}

void pick_up_forks(t_philosopher *philosopher) {
    int left_fork = philosopher->id - 1; // Assuming ID starts from 1
    int right_fork = philosopher->id % philosopher->shared->nb_philo; // Wrap around for the last philosopher

    if (philosopher->id % 2 == 0) {
        // Even ID philosophers pick up the right fork first
        pthread_mutex_lock(&(philosopher->shared->forks[right_fork]));
        // action_print(philosopher, "has taken a fork");

        pthread_mutex_lock(&(philosopher->shared->forks[left_fork]));
        // action_print(philosopher, "has taken a fork");
    } else {
        // Odd ID philosophers pick up the left fork first
        pthread_mutex_lock(&(philosopher->shared->forks[left_fork]));
        // action_print(philosopher, "has taken a fork");

        pthread_mutex_lock(&(philosopher->shared->forks[right_fork]));
        // action_print(philosopher, "has taken a fork");
    }
}

void put_down_forks(t_philosopher *philosopher) {
    int left = philosopher->id - 1; // Assuming ID starts from 1
    int right = philosopher->id % philosopher->shared->nb_philo; // Wrap around for the last philosopher
    pthread_mutex_unlock(&philosopher->shared->forks[left]);
    pthread_mutex_unlock(&philosopher->shared->forks[right]);
}

// void check_death(t_philosopher *philosopher) {
// 	pthread_mutex_lock(&philosopher->shared->write_mutex);
//     long long current_time = get_current_timestamp_ms();
//     long long time_since_last_meal = current_time - philosopher->last_meal_time;

//     if (time_since_last_meal >= philosopher->shared->time_to_die) {
// 		// printf("   Current Timestamp: %lld\n", get_current_timestamp_ms());
// 		// printf("        current_time: %lld\n", current_time);
// 		// printf("      last_meal_time: %lld\n", philosopher->last_meal_time);
// 		// printf("time_since_last_meal: %lld\n", time_since_last_meal);
// 		// printf("         time_to_die: %d\n", philosopher->shared->time_to_die);
//         printf("\033[0;30m%lld\033[0m %lld %d has died\n", current_time % MULTIPLIER, current_time - philosopher->shared->start_time, philosopher->id);
//         philosopher->shared->someone_died = 1;
//         // Optionally signal all threads to stop
//     }
// 	pthread_mutex_unlock(&philosopher->shared->write_mutex);
// }

void check_death(t_philosopher *philosopher) {
    pthread_mutex_lock(&philosopher->shared->write_mutex);
    long long current_time = get_current_timestamp_ms();
    long long time_since_last_meal = current_time - philosopher->last_meal_time;

    if (time_since_last_meal >= philosopher->shared->time_to_die) {
        // Log the death detection time for responsiveness measurement
        long long death_detected_time = get_current_timestamp_ms();

        printf("\033[0;31mDeath detected at: %lld ms\033[0m\n", death_detected_time);
        printf("\033[0;30m%lld\033[0m %lld %d has died\n", current_time % MULTIPLIER, current_time - philosopher->shared->start_time, philosopher->id);

        philosopher->shared->someone_died = 1;

        // Here, you could also log the death time to a file or another data structure
        // for later analysis or comparison with the monitor thread's detection time, if applicable.
    }
    pthread_mutex_unlock(&philosopher->shared->write_mutex);
}

void *philosopher_routine(void *arg) {
    t_philosopher *philosopher = (t_philosopher *)arg;

    while (!philosopher->shared->someone_died) {
		check_death(philosopher);
        thinking(philosopher);
		check_death(philosopher);
        pick_up_forks(philosopher);
        check_death(philosopher);
        eating(philosopher);
		check_death(philosopher);
        put_down_forks(philosopher);
		check_death(philosopher);
        sleeping(philosopher);
		check_death(philosopher);
    }

    return NULL;
}
