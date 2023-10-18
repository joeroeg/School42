#include <stddef.h>

void* bit_memset_zero(void* ptr, size_t size_in_bits, size_t num_times) {
    unsigned char* byte_ptr = (unsigned char*)ptr;
    size_t num_bytes = (size_in_bits + 7) / 8;  // Round up to the nearest byte

    for (size_t i = 0; i < num_bytes; ++i) {
        for (size_t j = 0; j < 8 && i * 8 + j < size_in_bits; ++j) {
            if (num_times > 0) {
                byte_ptr[i] &= ~(1 << j);  // Set bit to 0
                num_times--;
            } else {
                return ptr;  // All bits set 0, return
            }
        }
    }

    return ptr;
}

#include <stdio.h>

void print_buffer(const unsigned char* buffer, size_t size_in_bits) {
    printf("Buffer content: ");
    for (size_t i = 0; i < size_in_bits / 8; ++i) {
        printf("%02x ", buffer[i]);
    }
    printf("\n");
}

int main() {
    unsigned char buffer[2] = {0xFF, 0xFF};  // Initialize buffer: 11111111 11111111

    printf("Before: ");
    print_buffer(buffer, 16);  // Print initial buffer content

    bit_memset_zero(buffer, 16, 10);  // Set first 10 bits to 0

    printf("After: ");
    print_buffer(buffer, 16);  // Print updated buffer content

    return 0;
}
