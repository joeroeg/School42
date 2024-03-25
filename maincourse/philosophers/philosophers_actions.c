/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:13:28 by hezhukov          #+#    #+#             */
/*   Updated: 2024/03/24 11:26:54 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		pthread_mutex_lock(&philosopher->shared->satisfied_mutex);
		if (philosopher->shared->satisfied == philosopher->shared->nb_philo)
			philosopher->shared->all_ate = 1;
		pthread_mutex_unlock(&philosopher->shared->satisfied_mutex);
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

void	check_and_handle_death(t_philosopher *philosopher, int *someone_died)
{
	pthread_mutex_lock(&philosopher->shared->status_mutex);
	*someone_died = philosopher->shared->someone_died;
	pthread_mutex_unlock(&philosopher->shared->status_mutex);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;
	int				all_ate;
	int				someone_died;

	philosopher = (t_philosopher *)arg;
	while (true)
	{
		check_and_handle_death(philosopher, &someone_died);
		if (someone_died)
		{
			put_down_forks(philosopher);
			break ;
		}
		thinking(philosopher);
		pick_up_forks(philosopher);
		eating(philosopher);
		put_down_forks(philosopher);
		check_and_handle_satisfaction(philosopher, &all_ate);
		if (all_ate)
			break ;
		sleeping(philosopher);
		usleep(1000);
	}
	return (NULL);
}
