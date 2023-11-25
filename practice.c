#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
	int j = 0;
    int seen_before_av1[128] = {0};
	int seen_before_av2[128] = {0};

    if (argc == 3)
    {
        while ((argv[2][i]))
        {
            if (seen_before_av2[(int)argv[2][i]] == 0)
			{
				seen_before_av2[(int)argv[2][i]] = 1;
			}
            i++;
        }
		while ((argv[1][j]))
        {
            if (seen_before_av1[(int)argv[1][j]] == 0 && seen_before_av2[(int)argv[1][j]] == 1)
			{
				seen_before_av1[(int)argv[1][j]] = 1;
				write (1, &argv[1][j], 1);
			}
            j++;
        }
    }
    write(1, "\n", 1);
}
