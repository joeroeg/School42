#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MESSAGE "STOP!\n"
#define MSGLEN 19

static void sig_handler(int signal) {
	if (signal == SIGINT) write(STDOUT_FILENO, MESSAGE, MSGLEN);
}

int main()
{
	unsigned long counter = 0;
	// signal(SIGINT, SIG_IGN); /* this line ignores SIGINT (CTRL + C) input. To quite from a loop use CTRL + \ */
	while(1)
	{
		signal (SIGINT, sig_handler);
		printf("%lu\n", counter);
		counter++;
		usleep(250000);
	}
}
