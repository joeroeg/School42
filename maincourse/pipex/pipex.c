#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>


/*
    expected implementation: < infile ls -l | wc -l > outfile

    fd 0 = input
    fd 1 = output
    fd 2 = error

    pipe [0] = read
    pipe [1] = write



    1. redirect
*/


int main()
{

}
