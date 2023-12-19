// rostring
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    int start = 0;
    int end = 0;
    int flag = 0;

    if (argc < 2 )
        write(1, "\n", 1);
    else
    {
        while (argv[1][i] == ' ')
            i++;
        start = i;
        while (argv[1][i] && argv[1][i] != ' ')
            i++;
        end = i;
        while (argv[1][i] == ' ')
            i++;
        int more_than_one_word = argv[1][i] != '\0';
        while (argv[1][i]) {
            if (argv[1][i] == ' ' || argv[1][i] == '\t')
                flag = 1;
            else {
                if (flag) {
                    write(1, " ", 1);
                    flag = 0;
                }
                write(1, &argv[1][i], 1);
            }
            i++;
        }
        if (end > start)
        {
            if (flag || more_than_one_word)
                write(1, " ", 1);
        while (start < end)
        {
            write(1, &argv[1][start], 1);
            start++;
        }
    }
	    write(1, "\n", 1);
    }
    return 0;
}


/*
    // Skip initial spaces and tabs
    // Set the start of the first word
    // Find the end of the first word
    // Skip spaces and tabs
    // Check if there's more than one word
    // Skip spaces after the first word
    // Print the rest of the words
    // Print the first word at the end if it exists
*/
