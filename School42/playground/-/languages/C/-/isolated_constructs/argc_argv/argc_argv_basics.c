/*
# Overview

In the C programming language, argc and argv are parameters that are used to pass command line arguments to a program when it is executed.
- argc is an integer variable that represents the number of arguments passed to the program from the command line.
- The first argument, argv[0], is always the name of the program itself.
- The remaining arguments, argv[1] through argv[argc-1], are any additional command line arguments passed to the program.
- argv is a pointer to an array of character strings (i.e., an array of pointers to characters).
- Each element of this array represents one of the command line arguments passed to the program, with argv[0] being the name of the program itself.
- The last element of the array is a null pointer (i.e., a pointer that points to nothing).

./argc_argv_basics.c arg1 arg2 arg3 In this case, argc would be equal to 4 (including the program name), and argv would be an array of pointers to the following strings:

*/

#include<stdio.h>
int main(int argc, char *argv[]) {
    printf("The name of the program is %s\n", argv[0]);
    printf("The number of arguments passed is %d\n", argc-1);
    printf("The arguments are:\n");
    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    return 0;
}
