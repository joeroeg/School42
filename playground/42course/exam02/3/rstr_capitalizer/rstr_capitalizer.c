#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc < 2)
        write(1, "\n", 1);
    int i = 1;
    int j = 0;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] >= 'A' && argv[i][j] <= 'Z')
            {
                argv[i][j] = argv[i][j] + 32;
            }
            if (argv[i][j + 1] == '\0' || argv[i][j + 1] == ' ' || argv[i][j + 1] == '\t')
            {
                if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                {
                    argv[i][j] = argv[i][j] - 32;
                }
            }
            write(1, &argv[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}
