#include <stdio.h>
#include <stdlib.h> // Include the standard library for exit()

int main()
{
    int ch = 0;
    int c = 0;
    int nl = 0;
    int inword = 0;
    int nw = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == EOF)
        {
            if (ferror(stdin))
            {
                perror("Input error");
                exit(EXIT_FAILURE);
            }
            break;
        }
        ch++;
        if (c == '\n') // check for new lines
        nl++;
        if (c == ' ' || c == '\n' || c == '\t' || c == ',') // check for white characters if yes reset inword flag
        inword = 0;
        else if (inword == 0) // if previous condition false and inword 0 then set a flag inword 1 and increment.
        {
            inword = 1;
            nw++;
        }
        if (ferror(stdin))
        {
            perror("Input error");
            exit(EXIT_FAILURE);
        }
    }
    printf("char: %d nl: %d nw: %d\n", ch, nl, nw);
    return (0);
}