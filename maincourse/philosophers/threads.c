#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void *eating(void *arg)
{
    struct timespec start, end;

    for (int i = 0; i < 8; i++)
    {
    	clock_gettime(CLOCK_MONOTONIC, &start); // Measure start time
        sleep(2);
    	clock_gettime(CLOCK_MONOTONIC, &end); // Measure end time
		// Calculate the time difference
		double time_taken = (end.tv_sec - start.tv_sec) * 1e9;
		double time_taken_ms = ((end.tv_sec - start.tv_sec) * 1e3) + ((end.tv_nsec - start.tv_nsec) / 1e6);
        printf("eating   %.1f \n", time_taken_ms);
    }
    printf("eating   done\n");
    return NULL;
}


void *sleeping(void *arg)
{
	struct timespec start, end;

	for (int i = 0; i < 5; i++)
	{
    	clock_gettime(CLOCK_MONOTONIC, &start); // Measure start time]
		sleep(3);
		clock_gettime(CLOCK_MONOTONIC, &end); // Measure end time
		double time_taken = (end.tv_sec - start.tv_sec) * 1e9;
		double time_taken_ms = ((end.tv_sec - start.tv_sec) * 1e3) + ((end.tv_nsec - start.tv_nsec) / 1e6);
		printf("sleeping %.1f \n", time_taken_ms);
	}
	printf("sleeping done\n");
	return NULL;
}

void *thinking(void *arg)
{
	struct timespec start, end;

	for (int i = 0; i < 3; i++)
	{
    	clock_gettime(CLOCK_MONOTONIC, &start); // Measure start time
		sleep(4);
		clock_gettime(CLOCK_MONOTONIC, &end); // Measure end time
		// Calculate the time difference
		double time_taken = (end.tv_sec - start.tv_sec) * 1e9;
		double time_taken_ms = ((end.tv_sec - start.tv_sec) * 1e3) + ((end.tv_nsec - start.tv_nsec) / 1e6);
		printf("thinking %.1f \n", time_taken_ms);
	}
	printf("thinking done\n");
	return NULL;
}

void waiting()
{
	struct timespec start, end;

	for (int i = 0; i < 8; i++)
	{
    	clock_gettime(CLOCK_MONOTONIC, &start); // Measure start time
		sleep(1);
		clock_gettime(CLOCK_MONOTONIC, &end); // Measure end time
		// Calculate the time difference
		double time_taken = (end.tv_sec - start.tv_sec) * 1e9;
		double time_taken_ms = ((end.tv_sec - start.tv_sec) * 1e3) + ((end.tv_nsec - start.tv_nsec) / 1e6);
		printf("waiting  %.1f \n", time_taken_ms);
	}
	printf("waiting  done\n");
}

int main()
{
	pthread_t eating_thread;
	pthread_t sleeping_thread;
	pthread_t thinking_thread;

	pthread_create(&eating_thread, NULL, eating, NULL);
	pthread_create(&sleeping_thread, NULL, sleeping, NULL);
	pthread_create(&thinking_thread, NULL, thinking, NULL);
	waiting();
	pthread_join(eating_thread, NULL);
	pthread_join(sleeping_thread, NULL);
	pthread_join(thinking_thread, NULL);
}
