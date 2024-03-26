#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>

void    error(char *str)
{
    while (*str)
        write(2, str++, 1);
}

void cd(char **argv, int i)
{
    if (i != 2)
        return (error("error: cd: bad arguments\n"));
    else if (chdir(argv[1]) == -1)
        return (error("error: cd: cannot change directory to "), error(argv[1]), error("\n"));
}

void exec(char **argv, char **envp, int i)
{
    int status;
    int fds[2];
    int pip = (argv[i] && !strcmp(argv[i], "|")); // this is our flag for executing pipe if needed. Carefull! You must use &&
    if (pipe(fds) == -1)
        return (error("error: fatal\n"));
    int pid = fork();
    if (!pid)
    {
        argv[i] = 0; // we need to null terminate the argument list for execve program
        if (pip && (dup2(fds[1], 1) == -1 || close(fds[0]) || close(fds[1]))) // if pip is true then we need to redirect and close fds
            return (error("error: fatal\n"));
        execve(*argv, argv, envp);
        return (error("error: cannot execute "), error(*argv), error("\n"));
    }
    waitpid(pid, &status, 0);
    if (pip && (dup2(fds[0], 0) == -1 || close(fds[0]) || close(fds[1])))
        return (error("error: fatal\n"));
}

int main(int argc, char **argv, char **envp)
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
            exec(argv, envp, i);
        argv += i;
    }
}
