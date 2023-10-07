#include <stdio.h>
#include <unistd.h> // for sleep function


int main() {
    int totalSteps = 100;
    
    for (int i = 1; i <= totalSteps; ++i) {
        printf("Loading %3d%%", i * 1);
        fflush(stdout);
        usleep(50000); // sleep for 500 milliseconds

        // Erase the previous progress and return to the beginning of the line
        printf("\r");
    }

    printf("Loading 100%%\n");
    
    return 0;
}
