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
	pthread_t		id;
	pthread_mutex_t	*left_fork;
    pthread_mutex_t	*right_fork;

}	t_philosopher;

void initialize_forks();
void initialize_philosophers();

int main()
{

}
