#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	execute_command(char *fullpath, char *const argv[])
{
	if (fullpath)
	{
		execv(fullpath, argv);
		perror("execv");
		free(fullpath);
		return (-1);
	}
	else
	{
		fprintf(stderr, "Command not found\n");
		return (-1);
	}
}

int main() {
    char *fullpath = "/bin/ls"; // Example command to execute
    char *args[] = { "ls", "-l", NULL }; // Arguments for the command

    // Test with a valid command
    int result = execute_command(fullpath, args);
    printf("Result of execute_command with valid path: %d\n", result);

    // Test with a NULL fullpath
    result = execute_command(NULL, args);
    printf("Result of execute_command with NULL path: %d\n", result);

    return 0;
}
