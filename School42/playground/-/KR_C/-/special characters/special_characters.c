#include <stdio.h>
#include <unistd.h> // for sleep function

int main() {
    for (int i = 0; i < 10; ++i) {
        printf("Loading %d%%", i * 10);
        fflush(stdout); // flush the output
        sleep(1); // sleep for 1 second
        printf("\b\b\b\b\b\b\b\b\b\b"); // move the cursor back by 10 positions
    }
    
    return 0;
}
