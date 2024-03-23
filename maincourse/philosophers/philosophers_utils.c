/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:13:43 by hezhukov          #+#    #+#             */
/*   Updated: 2024/03/23 19:17:49 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_current_timestamp_ms(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000LL) + (now.tv_usec / 1000));
}

void	ft_usleep(long long time)
{
	long long	start;

	start = get_current_timestamp_ms();
	while (get_current_timestamp_ms() < start + time)
		usleep(10);
}

void	action_print(t_philosopher *philosopher, const char *action)
{
	long long	current_timestamp;
	long long	elapsed_time;

	pthread_mutex_lock(&(philosopher->shared->status_mutex));
	if (!philosopher->shared->someone_died)
	{
		current_timestamp = get_current_timestamp_ms();
		elapsed_time = current_timestamp - philosopher->shared->start_time;
		printf("%lli %d %s\n", elapsed_time, philosopher->id, action);
	}
	pthread_mutex_unlock(&(philosopher->shared->status_mutex));
}

int	ft_atoi(const char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (result > 2147483647 / 10 || \
			(result == 2147483647 / 10 && (str[i] - '0') > 2147483647 % 10))
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
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
