#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>

/*
1. (void) argc - to turn off errors
2. start a while loop
3. increment argv to skip the program name
4. reset i to 0
5. skip semicolon and pipe untill valid arguments
6. if cd execute cd
7. otherwise call exec function

exec
1. delcare status, fds[2], pip and pid (pid with fork);
2. initialize pipe for fds[2] and check for error and check for errors
3. fork the process
4. null terminate argv
5. if pip then redirect output to write to a pipe and close fds and check for errors
6. execute command and return an error if fails.
7. in parent waitpid
8. if pip then redirect input to read from a pipe close fds and check for errors
9.


while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
if (pip && (dup2(fds[1], 1) == -1 || close(fds[0]) || close(fds[1])))


Tests
1. Execute a wrong command and check for an error message
2.

*/

void error(char *str)
{
    while (*str)
        write(2, str++, 1);
}

void cd(char **argv, int i)
{
    if (i != 2)
        return (error("error: cd: bad arguments"), error(argv[1]), error("\n"));
    else if (chdir(argv[1]) == -1)
        return (error("error: fatal\n"));
}

void exec(char **argv, char **env, int i)
{
    int status;
    int fds[2];
    int pip = (argv[i] && !strcmp(argv[i], "|"));
    if (pipe(fds) == -1)
        return (error("error: fatal\n"));
    int pid = fork();
    if (!pid)
    {
        argv[i] = 0;
        if (pip && (dup2(fds[1], 1) == -1 || close(fds[0]) || close(fds[1])))
            return (error("error: fatal\n"));
        execve(*argv, argv, env);
            return (error("error: cannot execute "), error(argv[1]), error("\n"));
    }
    waitpid(pid, &status, 0);
    if (pip && (dup2(fds[0], 0) == -1 || close(fds[0]) || close(fds[1])))
        return (error("error: fatal\n"));
}

int main(int argc, char **argv, char **env)
{
    (void)argc;
    int i = 0;
    while (*argv && *(argv + 1))
    {
        ++argv;
        i = 0;
        while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
            i++;
        if (!strcmp(*argv, "cd"))
            cd(argv, i);
        else if (i)
            exec(argv, env, i);
        argv += i;
    }
}
