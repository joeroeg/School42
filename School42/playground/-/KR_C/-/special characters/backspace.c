#include <stdio.h>
#include <unistd.h> // for sleep function

int main() {
    printf("Loading 100%%");

    for (int i = 0; i < 11; ++i) {
        fflush(stdout); // flush the output
        usleep(500000); // sleep for 500 milliseconds
        printf("\b \b"); // erase the last character
    }
    return 0;
}
