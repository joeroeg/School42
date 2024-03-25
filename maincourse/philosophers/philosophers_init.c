/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:13:34 by hezhukov          #+#    #+#             */
/*   Updated: 2024/03/23 20:06:34 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_simulation_mutexes(t_simulation *sim)
{
	int	i;

	i = 0;
	if ((pthread_mutex_init(&sim->shared_resources.write_mutex, NULL) != 0 || \
		pthread_mutex_init(&sim->shared_resources.status_mutex, NULL) != 0) || \
		pthread_mutex_init(&sim->shared_resources.last_meal_time_mutex, \
			NULL) != 0 || \
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

int	initialize_shared_resources(char **argv, int argc, \
	t_shared_resources *shared)
{
	shared->start_time = get_current_timestamp_ms();
	shared->nb_philo = ft_atoi(argv[1]);
	shared->time_to_die = ft_atoi(argv[2]);
	shared->time_to_eat = ft_atoi(argv[3]);
	shared->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		shared->max_meals = ft_atoi(argv[5]);
	else
		shared->max_meals = -1;
	shared->satisfied = 0;
	shared->all_ate = 0;
	shared->someone_died = 0;
	return (EXIT_SUCCESS);
}

int	initialize_philosophers(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->shared_resources.nb_philo)
	{
		sim->philosophers[i].id = i + 1;
		sim->philosophers[i].meals_eaten = 0;
		sim->philosophers[i].last_meal_time = sim->shared_resources.start_time;
		sim->philosophers[i].shared = &sim->shared_resources;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_simulation(int argc, char **argv, t_simulation *sim)
{
	if (validate_simulation_params(argc, argv) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (initialize_shared_resources(argv, argc, \
		&sim->shared_resources) != EXIT_SUCCESS)
	{
		write(2, "Failed to initialize shared resources.\n", 39);
		return (EXIT_FAILURE);
	}
	if (init_simulation_mutexes(sim) != EXIT_SUCCESS)
	{
		write(2, "Failed to initialize mutexes.\n", 31);
		return (EXIT_FAILURE);
	}
	if (initialize_philosophers(sim) != EXIT_SUCCESS)
	{
		write(2, "Failed to initialize philosophers.\n", 36);
		cleanup_simulation(sim);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
