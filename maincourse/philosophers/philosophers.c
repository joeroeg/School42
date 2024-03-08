#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/**
 * @param N - number of philosophers and forks
*/
#define N 1

/**
 * @brief - main structure with parameters for philosophers.
 * @param id - each thread must have its own id
 * @param left_fork - represent mutex
 * @param right_fork - represent mutex
*/
typedef struct s_philosopher
{
	int				philosopher_number;
	pthread_t		id;
	pthread_mutex_t	*left_fork;
    pthread_mutex_t	*right_fork;

}	t_philosopher;

void initialize_forks();
void initialize_philosophers();

void *thread_function(void* arg)
{
    t_philosopher *philosopher = (t_philosopher*)arg;
    printf("Philosopher %d is thinking...\n", philosopher->philosopher_number);
    // Simulate philosopher's actions here.
    return NULL;
}

int main()
{
	t_philosopher philosophers[N];
	pthread_mutex_t	forks[N];


	int result = pthread_create(&philosophers->id, NULL, thread_function, NULL);
	if (result == 0)
	{
		// thread creation successful.
		pthread_join(philosophers->id, NULL);
	}
}
