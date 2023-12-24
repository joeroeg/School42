#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <spawn.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char **argv)
{
	char *args[4] = {"/bin/echo", "hello", 0};
	int child_status;
	int result;

	if (0 != posix_spawn(&result, args[0], NULL, NULL, args, environ))
	{
		perror("spawn failed");
		exit(1);
	}
	wait(&child_status);
}
