#include <stdio.h>
#include <stdbool.h>

int main()
{
    int ch = 0;
    int c = 0;
    int nl = 0;
    int nw = 0;
    bool inword = false;

    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n')
        {
            nl++;  // Increment newline count
            inword = false;  // Reset inword flag when encountering newline
        }
        else if (ch == ' ' || ch == '\t')
        {
            inword = false;  // Reset inword flag when encountering whitespace
        }
        else
        {
            c++;  // Increment character count
            if (!inword)
            {
                nw++;  // Increment word count if entering a new word
                inword = true;  // Set inword flag to indicate inside a word
            }
        }
    }
    
    printf("char: %d lines: %d words: %d\n", c, nl, nw);
    return 0;
}
