#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void swap_int(int *a, int *b)
{

}

int main(int argc, char *argv[]) {
    if (argc == 3) {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        swap_int(&a, &b);
        printf("%d %d ", a, b);
    }
    return 0;
}
