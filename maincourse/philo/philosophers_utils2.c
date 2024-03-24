/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:13:43 by hezhukov          #+#    #+#             */
/*   Updated: 2024/03/24 11:33:48 by hezhukov         ###   ########.fr       */
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

void	pick_up_forks(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->shared->satisfied_mutex);
	if (philosopher->shared->all_ate)
	{
		pthread_mutex_unlock(&philosopher->shared->satisfied_mutex);
		return ;
	}
	pthread_mutex_unlock(&philosopher->shared->satisfied_mutex);
	if (philosopher->id % 2 == 0)
	{
		pthread_mutex_lock(&(philosopher->shared->forks[philosopher->id % \
			philosopher->shared->nb_philo]));
		action_print(philosopher, "has taken a fork");
		pthread_mutex_lock(&(philosopher->shared->forks[philosopher->id - 1]));
		action_print(philosopher, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&(philosopher->shared->forks[philosopher->id - 1]));
		action_print(philosopher, "has taken a fork");
		pthread_mutex_lock(&(philosopher->shared->forks[philosopher->id % \
			philosopher->shared->nb_philo]));
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

void	check_and_handle_satisfaction(t_philosopher *philosopher, int *all_ate)
{
	pthread_mutex_lock(&philosopher->shared->satisfied_mutex);
	*all_ate = philosopher->shared->all_ate;
	pthread_mutex_unlock(&philosopher->shared->satisfied_mutex);
}
