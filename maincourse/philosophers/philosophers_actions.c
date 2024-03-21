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
}

void eating(t_philosopher *philosopher) {
    action_print(philosopher, "is eating");
	print_philosopher(philosopher);
	pthread_mutex_lock(&philosopher->shared->last_meal_time_mutex);
    philosopher->last_meal_time = get_current_timestamp_ms();
	pthread_mutex_unlock(&philosopher->shared->last_meal_time_mutex);
    ft_usleep(philosopher->shared->time_to_eat);
	philosopher->meals_eaten++;
}

void sleeping(t_philosopher *philosopher) {
    action_print(philosopher, "is sleeping");
    ft_usleep(philosopher->shared->time_to_sleep);
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

int check_death(t_philosopher *philosopher)
{
    long long current_time = get_current_timestamp_ms();
	pthread_mutex_lock(&philosopher->shared->last_meal_time_mutex);
    long long time_since_last_meal = current_time - philosopher->last_meal_time;
	pthread_mutex_unlock(&philosopher->shared->last_meal_time_mutex);

    if (time_since_last_meal >= philosopher->shared->time_to_die)
	{
    	pthread_mutex_lock(&philosopher->shared->status_mutex);
        printf("\033[0;31m%lld %lld %d has died\033[0m\n", current_time % MULTIPLIER, current_time - philosopher->shared->start_time, philosopher->id);
        philosopher->shared->someone_died = 1;
        pthread_mutex_unlock(&philosopher->shared->status_mutex);
        return 1; // Philosopher has died
    }
    return 0; // Philosopher is still alive
}

void *philosopher_routine(void *arg) {
    t_philosopher *philosopher = (t_philosopher *)arg;

    while (!philosopher->shared->someone_died) {
        thinking(philosopher);
        pick_up_forks(philosopher);
        eating(philosopher);
        put_down_forks(philosopher);
        sleeping(philosopher);
    }
    return NULL;
}
