#include <stdio.h>
#include <unistd.h> // for sleep function

int main() {
    for (int i = 0; i <= 100; i += 10) {
        printf("Progress: [%3d%%]", i);
        fflush(stdout);
        usleep(50000); // sleep for 50 milliseconds
        printf("\r"); // carriage return to the beginning of the line
    }
    printf("\n");
    return 0;
}

