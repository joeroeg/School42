#include "philosophers.h"

void	thinking(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->shared->satisfied_mutex);
	if (philosopher->shared->all_ate)
	{
		pthread_mutex_unlock(&philosopher->shared->satisfied_mutex);
		return ;
	}
	pthread_mutex_unlock(&philosopher->shared->satisfied_mutex);
	action_print(philosopher, "is thinking");
}

void	eating(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->shared->satisfied_mutex);
	if (philosopher->shared->all_ate)
	{
		pthread_mutex_unlock(&philosopher->shared->satisfied_mutex);
		return ;
	}
	pthread_mutex_unlock(&philosopher->shared->satisfied_mutex);
	action_print(philosopher, "is eating");
	pthread_mutex_lock(&philosopher->shared->last_meal_time_mutex);
	philosopher->last_meal_time = get_current_timestamp_ms();
	pthread_mutex_unlock(&philosopher->shared->last_meal_time_mutex);
	pthread_mutex_lock(&philosopher->shared->meal_mutex);
	ft_usleep(philosopher->shared->time_to_eat);
	philosopher->meals_eaten++;
	pthread_mutex_unlock(&philosopher->shared->meal_mutex);
	if (philosopher->meals_eaten == philosopher->shared->max_meals)
	{
		pthread_mutex_lock(&philosopher->shared->satisfied_mutex);
		philosopher->shared->satisfied++;
		pthread_mutex_unlock(&philosopher->shared->satisfied_mutex);
		if (philosopher->shared->satisfied == philosopher->shared->nb_philo)
			philosopher->shared->all_ate = 1;
	}
}

void	sleeping(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->shared->satisfied_mutex);
	if (philosopher->shared->all_ate)
	{
		pthread_mutex_unlock(&philosopher->shared->satisfied_mutex);
		return ;
	}
	pthread_mutex_unlock(&philosopher->shared->satisfied_mutex);
	action_print(philosopher, "is sleeping");
	ft_usleep(philosopher->shared->time_to_sleep);
}

void	pick_up_forks(t_philosopher *philosopher)
{
	int	left_fork;
	int	right_fork;

	left_fork = philosopher->id - 1;
	right_fork = philosopher->id % philosopher->shared->nb_philo;
	pthread_mutex_lock(&philosopher->shared->satisfied_mutex);
	if (philosopher->shared->all_ate)
	{
		pthread_mutex_unlock(&philosopher->shared->satisfied_mutex);
		return ;
	}
	pthread_mutex_unlock(&philosopher->shared->satisfied_mutex);
	if (philosopher->id % 2 == 0)
	{
		pthread_mutex_lock(&(philosopher->shared->forks[right_fork]));
		action_print(philosopher, "has taken a fork");
		pthread_mutex_lock(&(philosopher->shared->forks[left_fork]));
		action_print(philosopher, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&(philosopher->shared->forks[left_fork]));
		action_print(philosopher, "has taken a fork");
		pthread_mutex_lock(&(philosopher->shared->forks[right_fork]));
		action_print(philosopher, "has taken a fork");
	}
}

void	put_down_forks(t_philosopher *philosopher)
{
	int	left;
	int	right;

	left = philosopher->id - 1;
	right = philosopher->id % philosopher->shared->nb_philo;
	pthread_mutex_unlock(&philosopher->shared->forks[left]);
	pthread_mutex_unlock(&philosopher->shared->forks[right]);
}

void *philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;
	int				all_ate;
	int				someone_died;

	philosopher = (t_philosopher *)arg;
	all_ate = 0;
	while (true)
	{
		pthread_mutex_lock(&philosopher->shared->status_mutex);
		someone_died = philosopher->shared->someone_died;
		pthread_mutex_unlock(&philosopher->shared->status_mutex);
		if (someone_died)
		{
			put_down_forks(philosopher);
			break ;
		}
		thinking(philosopher);
		pick_up_forks(philosopher);
		eating(philosopher);
		pthread_mutex_lock(&philosopher->shared->satisfied_mutex);
		all_ate = philosopher->shared->all_ate;
		pthread_mutex_unlock(&philosopher->shared->satisfied_mutex);
		if (all_ate)
		{
			put_down_forks(philosopher);
			break ;
		}
		put_down_forks(philosopher);
		sleeping(philosopher);
		usleep(1000);
	}
	return (NULL);
}
