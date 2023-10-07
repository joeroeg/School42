#include <stdio.h>

/*
get a character
while (character is not end file signal)
    output the character just read
    get a new character

Converting this into C gives:
*/

main() /* copy input to output; 1st version */
{
    int c;
    c = getchar();

    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}

