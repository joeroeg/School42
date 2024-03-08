#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *eating(void *arg)
{
	for (int i = 0; i < 8; i++)
	{
		sleep(1);
		printf("eating   %d \n", i);
	}
	printf("eating   done\n");
	return NULL;
}

void *sleeping(void *arg)
{
	for (int i = 0; i < 3; i++)
	{
		sleep(2);
		printf("sleeping %d \n", i);
	}
	printf("sleeping done\n");
	return NULL;
}

void *thinking(void *arg)
{
	for (int i = 0; i < 5; i++)
	{
		sleep(2);
		printf("thinking %d \n", i);
	}
	printf("thinking done\n");
	return NULL;
}

void waiting()
{
	for (int i = 0; i < 8; i++)
	{
		sleep(2);
		printf("waiting  %d \n", i);
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
