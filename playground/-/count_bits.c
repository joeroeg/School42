#include <stdio.h>

int countBits(unsigned int number) {
    int count = 0;
    while (number) {
        count++;
        number >>= 1; // Shift number one bit to the right
    }
    return count;
}

int main() {
    unsigned int limit = 1024; // Example number
	for (int i = 0; i <= limit; i++)
	{
		printf("Number of bits in %u is %d\n", i, countBits(i));
	}
    return 0;
}
