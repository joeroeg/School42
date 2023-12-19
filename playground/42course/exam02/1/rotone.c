#include <unistd.h>


int main(int argc, char *argv[])
{
    int i = 0;
    char c;

    if (argc == 2)
    {
        while ((c = argv[1][i]) != '\0')
        {
            if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z'))
                c++;
            else if (c == 'z')
                c = 'a';
            else if (c == 'Z')
                c = 'A';

            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
