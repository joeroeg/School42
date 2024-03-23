#include <stdio.h>

int ft_atoi(const char *str) {
    int result = 0;
	int i = 0;

    // Check for null pointer
    if (!str) {
        return 0; // Signal error or invalid input
    }
	// rewrite with while loop
	while (str[i] != '\0')
	{
		// Ensure character is a digit
		if (str[i] < '0' || str[i] > '9') {
			return 0; // Signal error or invalid input
		}

		// Check for potential overflow
		if (result > 2147483647 / 10 || (result == 2147483647 / 10 && (str[i] - '0') > 2147483647 % 10)) {
			return 0; // Could also signal overflow differently, if desired
		}

		// Accumulate digit value
		result = result * 10 + (str[i] - '0');
		i++;
	}
    return result;
}

int main() {
    // Test cases
    printf("1234 yields %d\n", ft_atoi("1234")); // Expected: 1234
    printf("abcd yields %d\n", ft_atoi("abcd")); // Expected: 0 (error/invalid)
    printf("12a34 yields %d\n", ft_atoi("12a34")); // Expected: 0 (error/invalid)
    printf("9999999999 yields %d\n", ft_atoi("9999999999")); // Potential overflow, expect 0 or a discussion on handling this scenario

    return 0;
}
