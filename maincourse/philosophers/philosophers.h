#ifndef PHILOSOPHERS
#define PHILOSOPHERS_H
#endif

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_PHILOSOPHERS 256 // Maximum number of philosophers
#define MULTIPLIER 100000 // Multiplier to convert seconds to milliseconds

// Structure to hold shared resources and simulation rules
typedef struct s_shared_resources {
    int					nb_philo; // Number of philosophers
    int					time_to_die; // Maximum time between meals before a philosopher dies
    int					time_to_eat; // Time it takes for a philosopher to eat
    int					time_to_sleep; // Time a philosopher spends sleeping
	int					time_to_think; // Time a philosopher spends thinking
    int					max_meals; // Optional: Number of meals each philosopher should eat before simulation ends
    long long			start_time; // Timestamp when the simulation starts
    pthread_mutex_t		forks[MAX_PHILOSOPHERS]; // Mutex for each fork
    pthread_mutex_t		write_mutex; // Mutex for writing to stdout to prevent interleaving
    pthread_mutex_t		status_mutex; // Mutex for checking/updating philosopher's status (alive or dead)
	pthread_mutex_t		last_meal_time_mutex; // Mutex for checking the last meal time
    int					all_ate; // Flag to check if all philosophers have eaten `max_meals` times
    int					someone_died; // Flag to indicate if any philosopher has died
} t_shared_resources;

// Structure to represent each philosopher
typedef struct s_philosopher {
    int					id; // Philosopher's unique identifier
    long long			last_meal_time; // Timestamp of the last meal
    int 				meals_eaten; // Count of how many times the philosopher has eaten
    t_shared_resources	*shared; // Pointer to shared resources and rules
    pthread_t 			thread; // Thread running this philosopher's lifecycle
} t_philosopher;

typedef struct s_simulation {
    t_shared_resources	shared_resources;
    t_philosopher		philosophers[MAX_PHILOSOPHERS];
} t_simulation;

// Initialization
int		init_simulation(int argc, char **argv, t_simulation *sim);
void	cleanup_simulation(t_simulation *sim);

// Utilities
long long	get_current_timestamp_ms();
// void		ft_usleep(long long timeInMilliseconds, t_shared_resources *rules);
void		ft_usleep(long long time);
void		action_print(t_philosopher *philosopher, const char *action);
void		print_simulation_state(const t_simulation *sim);

// void thinking(void *arg);
void *philosopher_routine(void *arg);
void thinking(t_philosopher *philosopher);
void eating(t_philosopher *philosopher);
void sleeping(t_philosopher *philosopher);

// void check_death(t_philosopher *philosopher);
int check_death(t_philosopher *philosopher);
