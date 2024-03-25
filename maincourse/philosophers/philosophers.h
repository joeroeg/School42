/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:13:02 by hezhukov          #+#    #+#             */
/*   Updated: 2024/03/23 20:03:01 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <stdint.h>
# include <stdbool.h>

// Maximum number of philosophers
# define MAX_PHILOSOPHERS 200
# define MULTIPLIER 100000

/**
 * @brief Structure to hold shared resources and simulation rules
 * @param nb_philo Number of philosophers
 * @param time_to_die Maximum time between meals before a philosopher dies
 * @param time_to_eat Time it takes for a philosopher to eat
 * @param time_to_sleep Time a philosopher spends sleeping
 * @param time_to_think Time a philosopher spends thinking
 * @param max_meals Optional: Number of meals each philosopher should eat
 * @param start_time Timestamp when the simulation starts
 * @param forks Mutex for each fork
 * @param write_mutex Mutex for writing to stdout to prevent interleaving
 * @param status_mutex for checking/updating philosopher's status (alive or dead)
 * @param last_meal_time_mutex Mutex for checking the last meal time
 * @param meal_mutex Mutex for checking the last meal time
 * @param satisfied_mutex Mutex for checking the last meal time
 * @param all_ate Flag to check if all philosophers have eaten `max_meals` times
 * @param someone_died Flag to indicate if any philosopher has died
 * @param satisfied indicate if all philosophers have eaten `max_meals` times
*/

typedef struct s_shared_resources
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_think;
	int					max_meals;
	long long			start_time;
	pthread_mutex_t		forks[MAX_PHILOSOPHERS];
	pthread_mutex_t		write_mutex; // is not used
	pthread_mutex_t		status_mutex;
	pthread_mutex_t		last_meal_time_mutex;
	pthread_mutex_t		meal_mutex;
	pthread_mutex_t		satisfied_mutex;
	int					all_ate;
	int					someone_died;
	int					satisfied;
}	t_shared_resources;

/**
 * @brief Structure to represent each philosopher
 * @param id Philosopher's unique identifier
 * @param last_meal_time Timestamp of the last meal
 * @param meals_eaten Count of how many times the philosopher has eaten
 * @param shared Pointer to shared resources and rules
 * @param thread Thread running this philosopher's lifecycle
*/
typedef struct s_philosopher
{
	int					id;
	long long			last_meal_time;
	int					meals_eaten;
	t_shared_resources	*shared;
	pthread_t			thread;
}	t_philosopher;

/**
 * @brief Structure to represent the simulation
 * @param shared_resources Shared resources and rules
 * @param philosophers Array of philosophers
*/
typedef struct s_simulation
{
	t_shared_resources	shared_resources;
	t_philosopher		philosophers[MAX_PHILOSOPHERS];
}	t_simulation;

int			init_simulation(int argc, char **argv, t_simulation *sim);
void		cleanup_simulation(t_simulation *sim);
long long	get_current_timestamp_ms(void);
void		ft_usleep(long long time);
void		action_print(t_philosopher *philosopher, const char *action);
void		print_simulation_state(const t_simulation *sim);
int			ft_atoi(const char *str);
void		pick_up_forks(t_philosopher *philosopher);
void		put_down_forks(t_philosopher *philosopher);
void		cleanup_simulation(t_simulation *sim);
int			validate_simulation_params(int argc, char **argv);
void		*philosopher_routine(void *arg);
void		thinking(t_philosopher *philosopher);
void		eating(t_philosopher *philosopher);
void		sleeping(t_philosopher *philosopher);
int			check_death(t_philosopher *philosopher);
void		check_and_handle_satisfaction(t_philosopher *philosopher, \
	int *all_ate);
#endif
