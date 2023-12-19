#include <stdio.h>
#include <stdlib.h>

unsigned char reverse_bits(unsigned char octet);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s byte\n", argv[0]);
        return 1;
    }

    unsigned char octet = (unsigned char)atoi(argv[1]);
    unsigned char result = reverse_bits(octet);

    printf("Reversed: %u\n", (unsigned int)result);

    return 0;
}
