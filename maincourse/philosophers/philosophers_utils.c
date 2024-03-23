#include "philosophers.h"

long long get_current_timestamp_ms() {
    struct timeval now;
    gettimeofday(&now, NULL);
    return (now.tv_sec * 1000LL) + (now.tv_usec / 1000);
}

void	ft_usleep(long long time)
{
	long long	start;

	start = get_current_timestamp_ms();
	while (get_current_timestamp_ms() < start + time)
		usleep(10);
}

void action_print(t_philosopher *philosopher, const char *action) {
    pthread_mutex_lock(&(philosopher->shared->status_mutex));
    if (!philosopher->shared->someone_died) {
        long long current_timestamp = get_current_timestamp_ms();
        long long elapsed_time = current_timestamp - philosopher->shared->start_time;
		printf("%lli %d %s\n", elapsed_time, philosopher->id, action);
    }
    pthread_mutex_unlock(&(philosopher->shared->status_mutex));
}

void print_simulation_state(const t_simulation *sim) {
    if (!sim) {
        printf("Simulation pointer is NULL.\n");
        return;
    }

	printf("-----------------------------------------------------------\n");
    printf("Shared Resources:\n");
    printf("            Philosophers: %d\n", sim->shared_resources.nb_philo);
    printf("             Time to Die: %d\n", sim->shared_resources.time_to_die);
    printf("             Time to Eat: %d\n", sim->shared_resources.time_to_eat);
    printf("           Time to Sleep: %d\n", sim->shared_resources.time_to_sleep);
    printf("               Max Meals: %d\n", sim->shared_resources.max_meals);
    printf("              Start Time: %lld\n", sim->shared_resources.start_time % MULTIPLIER);
    printf("           Someone Died: %d\n", sim->shared_resources.someone_died);

    printf("\nPhilosophers:\n");
    for (int i = 0; i < sim->shared_resources.nb_philo; i++) {
        printf("      Philosopher %d:\n", sim->philosophers[i].id);
        printf("         Meals Eaten: %d\n", sim->philosophers[i].meals_eaten);
        printf("      Last Meal Time: %lld\n", sim->philosophers[i].last_meal_time % MULTIPLIER);
		printf("Expected Time to Die: %lld\n", (sim->philosophers[i].last_meal_time % MULTIPLIER)+ sim->shared_resources.time_to_die % 10000);
        // Not printing the 'shared' pointer as it points to the shared_resources already printed
        // Not printing the thread ID as it's not easily represented in a printout
    }
	printf("-----------------------------------------------------------\n");
}

int ft_atoi(const char *str) {
    int	result;
	int	i;

	result = 0;
	i = 0;
    if (!str)
        return 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
		if (result > 2147483647 / 10 || (result == 2147483647 / 10 && (str[i] - '0') > 2147483647 % 10))
			return 0;
		result = result * 10 + (str[i] - '0');
		i++;
	}
    return (result);
}
