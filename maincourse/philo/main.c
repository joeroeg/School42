/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:12:54 by hezhukov          #+#    #+#             */
/*   Updated: 2024/03/23 20:06:30 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_death(t_philosopher *philosopher)
{
	long long	current_time;
	long long	time_since_last_meal;

	current_time = get_current_timestamp_ms();
	pthread_mutex_lock(&philosopher->shared->last_meal_time_mutex);
	time_since_last_meal = current_time - philosopher->last_meal_time;
	pthread_mutex_unlock(&philosopher->shared->last_meal_time_mutex);
	if (time_since_last_meal >= philosopher->shared->time_to_die)
	{
		pthread_mutex_lock(&philosopher->shared->status_mutex);
		printf("%lld %d has died\n", \
			current_time - philosopher->shared->start_time, philosopher->id);
		philosopher->shared->someone_died = 1;
		pthread_mutex_unlock(&philosopher->shared->status_mutex);
		return (1);
	}
	return (0);
}

void	*death_monitor_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	while (true)
	{
		ft_usleep(1);
		pthread_mutex_lock(&philosopher->shared->status_mutex);
		if (philosopher->shared->someone_died)
		{
			pthread_mutex_unlock(&philosopher->shared->status_mutex);
			break ;
		}
		pthread_mutex_unlock(&philosopher->shared->status_mutex);
		pthread_mutex_lock(&philosopher->shared->satisfied_mutex);
		if (philosopher->shared->satisfied == philosopher->shared->nb_philo)
		{
			pthread_mutex_unlock(&philosopher->shared->satisfied_mutex);
			break ;
		}
		pthread_mutex_unlock(&philosopher->shared->satisfied_mutex);
		if (check_death(philosopher))
			break ;
	}
	return (NULL);
}

void	start_philosopher_threads(t_simulation *sim)
{
	pthread_t	monitor_thread;
	int			i;

	i = 0;
	while (i < sim->shared_resources.nb_philo)
	{
		if (pthread_create(&sim->philosophers[i].thread, NULL, \
			philosopher_routine, (void *)&sim->philosophers[i]) != 0)
			write(2, "Error creating philosopher thread\n", 35);
		if (pthread_create(&monitor_thread, NULL, \
			death_monitor_routine, (void *)&sim->philosophers[i]) != 0)
			write(2, "Error creating monitor thread\n", 31);
		pthread_detach(monitor_thread);
		i++;
	}
}

void	join_philosopher_threads(t_simulation *sim)
{
	int	i;

	i = 0;
	if (sim->shared_resources.nb_philo == 1)
	{
		ft_usleep(sim->shared_resources.time_to_die);
		return ;
	}
	while (i < sim->shared_resources.nb_philo)
	{
		pthread_join(sim->philosophers[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_simulation	sim;

	if (argc < 5 || argc > 6)
	{
		write(2, "Error: Invalid number of arguments\n", 36);
		return (EXIT_FAILURE);
	}
	if (init_simulation(argc, argv, &sim) != 0)
	{
		write(2, "Failed to initialize simulation.\n", 34);
		return (EXIT_FAILURE);
	}
	start_philosopher_threads(&sim);
	join_philosopher_threads(&sim);
	cleanup_simulation(&sim);
	return (EXIT_SUCCESS);
}
