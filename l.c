#include <stdio.h>
#include <unistd.h>

int main() {
    for(int i = 0; i <= 100; i++) {
        printf("Loading: %d%%\r", i);
        fflush(stdout);
        usleep(50000);  // Sleep for 50 milliseconds
    }
    printf("\nDone!\n");
    return 0;
}
