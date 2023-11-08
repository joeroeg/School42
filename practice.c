#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdarg.h>

int ft_print_p(va_list *args)
{
    uintptr_t ptr_val = va_arg(*args, uintptr_t);
    char buffer[16] = {0};  // Initialize all to zero
    char *digits = "0123456789abcdef";
    int len = 0;
    int index = 0;

    // Special case when pointer is zero
    if (ptr_val == 0) {
        write(1, "0x0", 3);
        return 3; // "0x" + "0" makes 3 characters
    }

    // Convert pointer to hex string from the end
    while (ptr_val != 0) {
        buffer[index++] = digits[ptr_val % 16];
        ptr_val /= 16;
    }

    // Print the '0x' prefix
    write(1, "0x", 2);
    len += 2; // Start len at 2 for the "0x"

    // Print the buffer in reverse order since the most significant digit is at the end
    while (index > 0) {
        write(1, &buffer[--index], 1);
        len++;
    }

    return len;
}

int print_pointer_wrapper(uintptr_t ptr, ...) {
    va_list args;
    int printed_length;

    va_start(args, ptr);
    printed_length = ft_print_p(&args);
    va_end(args);

    return printed_length;
}

int main() {
    uintptr_t test_ptr = (uintptr_t)&test_ptr; // Get the address of test_ptr itself as a test value
	int null = 0;
    // Call the wrapper function which will in turn call ft_print_p
    print_pointer_wrapper(null);

    return 0;
}
