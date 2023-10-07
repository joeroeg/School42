#include <stdio.h>
#include <unistd.h>

// Using a Loop and printf:
// Iterate through the argv array and use printf to print each argument.

for (int i = 0; i < argc; i++)
{
    printf("Argument %d: %s\n", i, argv[i]);
}


// Using write function:
// Use the write function to write the arguments to the standard output.

for (int i = 0; i < argc; i++)
{
    size_t length = strlen(argv[i]);
    write(STDOUT_FILENO, argv[i], length);
    write(STDOUT_FILENO, "\n", 1);
}


// Using fputs:
// Use the fputs function to write the arguments to the standard output.

for (int i = 0; i < argc; i++)
{
    fputs(argv[i], stdout);
    putchar('\n');
}


// Using putchar and putchar:
// Use putchar to print each character of the arguments and putchar for a newline.

for (int i = 0; i < argc; i++)
{
    for (int j = 0; argv[i][j] != '\0'; j++) {
        putchar(argv[i][j]);
    }
    putchar('\n');
}




#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    while ()
    for (int i = 0; i < argc; i++)
    {
        int length = 0;
        while (argv[i][length] != '\0')
        {
            length++;
        }
        write(1, argv[i], length);
        write(1, "\n", 1);
        }
}



//


write(1, argv[1]++, 1);
In the first implementation (write(1, argv[1]++, 1)), the ampersand (&) operator is not needed because argv[1] already points to the character to be written.


write(1, &argv[1][i++], 1);
In the second implementation (write(1, &argv[1][i++], 1)), the ampersand (&) operator is used to obtain the address of the character at the i-th position in the string.
This is required because the write system call expects a pointer to the data to be written.


If the number of parameters is not 1,  the program displays 'z' followed by a newline.
if (argc != 2)

If the number of arguments is less than 1, the program displays \n.
if (argc < 2)
if (argc >= 2)