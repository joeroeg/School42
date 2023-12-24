#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <spawn.h>
#include <stdlib.h>

int main()
{
	char *args[4] = {"/bin/echo", "hello", 0};
	int child_status;
	int result = fork();
	if (result < 0)
	{
		perror("fork failed");
		exit(1);
	}
	if (result == 0) // true branch is related to a child process
	{
		execv(args[0], args);
		perror("execv failed");
		exit(1);
	}
	else {
		wait(&child_status); // else branch is related to a parent process
	}
}
