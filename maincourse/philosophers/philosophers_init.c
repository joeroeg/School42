/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:13:34 by hezhukov          #+#    #+#             */
/*   Updated: 2024/03/23 19:14:12 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	cleanup_simulation(t_simulation *sim)
{
	int	i;

	i = 0;
	if (!sim)
		return ;
	pthread_mutex_destroy(&sim->shared_resources.write_mutex);
	pthread_mutex_destroy(&sim->shared_resources.status_mutex);
	pthread_mutex_destroy(&sim->shared_resources.last_meal_time_mutex);
	pthread_mutex_destroy(&sim->shared_resources.satisfied_mutex);
	while (i < sim->shared_resources.nb_philo)
	{
		pthread_mutex_destroy(&sim->shared_resources.forks[i]);
		i++;
	}
}

int	validate_simulation_params(int argc, char **argv)
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meals;

	nb_philo = ft_atoi(argv[1]);
	time_to_die = ft_atoi(argv[2]);
	time_to_eat = ft_atoi(argv[3]);
	time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		max_meals = ft_atoi(argv[5]);
	else
		max_meals = -1;
	if (nb_philo <= 0 || nb_philo > MAX_PHILOSOPHERS || \
		time_to_die <= 0 || time_to_eat <= 0 || time_to_sleep <= 0 || \
		(argc == 6 && max_meals < 0))
	{
		write(2, "Invalid All parameters must be positive integers.\n", 50);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_simulation_mutexes(t_simulation *sim)
{
	int	i;

	i = 0;
	if ((pthread_mutex_init(&sim->shared_resources.write_mutex, NULL) != 0 || \
		pthread_mutex_init(&sim->shared_resources.status_mutex, NULL) != 0) || \
		pthread_mutex_init(&sim->shared_resources.last_meal_time_mutex, NULL) != 0 || \
		pthread_mutex_init(&sim->shared_resources.satisfied_mutex, NULL) != 0)
	{
		write(2, "Failed to initialize control mutexes.\n", 38);
		return (-1);
	}
	while (i < sim->shared_resources.nb_philo)
	{
		if (pthread_mutex_init(&sim->shared_resources.forks[i], NULL) != 0)
		{
			write(2, "Failed to initialize fork mutex.\n", 34);
			cleanup_simulation(sim);
			return (-1);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_philosophers(t_simulation *sim)
{
	int	i;

	i = 0;
	if (!sim || sim->shared_resources.nb_philo <= 0)
	{
		write(2, "Invalid simulation or configuration.\n", 37);
		return (EXIT_FAILURE);
	}
	while (i < sim->shared_resources.nb_philo)
	{
		sim->philosophers[i].id = i + 1;
		sim->philosophers[i].meals_eaten = 0;
		sim->philosophers[i].last_meal_time = 0;
		sim->philosophers[i].shared = &sim->shared_resources;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_simulation(int argc, char **argv, t_simulation *sim)
{
	long long	start_time;
	int			i;

	i = 0;
	if (validate_simulation_params(argc, argv) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	start_time = get_current_timestamp_ms();
	sim->shared_resources.start_time = start_time;
	sim->shared_resources.nb_philo = ft_atoi(argv[1]);
	sim->shared_resources.time_to_die = ft_atoi(argv[2]);
	sim->shared_resources.time_to_eat = ft_atoi(argv[3]);
	sim->shared_resources.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		sim->shared_resources.max_meals = ft_atoi(argv[5]);
	else
		sim->shared_resources.max_meals = -1;
	sim->shared_resources.satisfied = 0;
	sim->shared_resources.all_ate = 0;
	sim->shared_resources.someone_died = 0;
	if (init_simulation_mutexes(sim) != EXIT_SUCCESS)
	{
		write(2, "Failed to initialize mutexes.\n", 31);
		return (EXIT_FAILURE);
	}
	if (init_philosophers(sim) != EXIT_SUCCESS)
	{
		write(2, "Failed to initialize philosophers.\n", 36);
		cleanup_simulation(sim);
		return (EXIT_FAILURE);
	}
	while (i < sim->shared_resources.nb_philo)
	{
		sim->philosophers[i].id = i + 1;
		sim->philosophers[i].meals_eaten = 0;
		sim->philosophers[i].last_meal_time = start_time;
		sim->philosophers[i].shared = &sim->shared_resources;
		i++;
	}
	return (EXIT_SUCCESS);
}
