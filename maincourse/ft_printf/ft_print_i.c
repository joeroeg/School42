#include "ft_printf.h"

int ft_print_i(va_list *args) {
	int num = va_arg(*args, int);
	int len = 0;
	unsigned int temp_num = num;
	char buffer[11]; // Integers can be up to 10 digits long, plus the sign
	int is_negative = num < 0;

	// Check if the number is negative
	if (is_negative) {
		num = (unsigned int) -num; // Make the number positive for processing
		len++;
	}

	// Count the number of digits to process
	int num_digits = 0;
	temp_num = (unsigned int) num; // Reset temp_num to the positive number
	if (temp_num == 0) {
		num_digits = 1;
	} else {
		while (temp_num != 0) {
			temp_num /= 10;
			num_digits++;
		}
	}

	// Fill the buffer in reverse order
	buffer[num_digits] = '\0';
	int i = num_digits - 1;
	temp_num = num; // Reset temp_num to the positive number
	while (i >= 0) {
		buffer[i] = (temp_num % 10) + '0'; // Convert the digit to its ASCII representation
		temp_num /= 10;
		i--;
	}

	// Write the negative sign if necessary
	if (is_negative) {
		write(1, "-", 1);
	}

	// Write the buffer to stdout
	write(1, buffer, num_digits);
	len += num_digits;

	return (len); // Return the number of characters printed
}
