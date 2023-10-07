#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_PRIME_COUNT 10
#define CSV_LINE_MAX_LENGTH 20

unsigned long long ft_random(unsigned int seed) {
    const long long int a = 22695477;  // Multiplier
    const long long int c = 1;         // Increment
    const long long int m = 4294967296; // Modulus (2^32)

    seed = (a * seed + c) % m;
    return seed;
}

long long ft_power(long long a, long long b, long long c) {
    long long result = 1;
    a %= c;

    while (b > 0) {
        if (b & 1)
            result = (result * a) % c;

        b >>= 1;
        a = (a * a) % c;
    }

    return result;
}

int ft_is_prime(long long n, int k) {
    if (n == 2)
        return 1;
    
    long long d = n - 1;
    while (d & 1)
        d >>= 1;

    for (int i = 0; i < k; i++) {
        long long a = 2 + ft_random(i) % (n - 4);

        if (ft_power(a, d, n) == 1)
            continue;

        int probablePrime = 0;
        long long x = d;
        while (x != n - 1) {
            if ((x & 1) && ft_power(a, x, n) == n - 1) {
                probablePrime = 1;
                break;
            }
            x >>= 1;
        }

        if (!probablePrime)
            return 0;
    }

    return 1;
}

int main() {
    FILE *file = fopen("prime_numbers.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[CSV_LINE_MAX_LENGTH];
    long long prime;
    int line_number = 1;
    int error_count = 0;

    // Read each line (prime) from the CSV file
    while (fgets(line, sizeof(line), file) && line_number <= MAX_PRIME_COUNT) {
        prime = strtoll(line, NULL, 10);

        // Check if the number is probably prime using ft_is_prime
        int is_probably_prime = ft_is_prime(prime, 10);

        // Validate the result
        if ((prime == 2 && !is_probably_prime) || (prime != 2 && is_probably_prime)) {
            printf("Error at line %d: %lld is incorrectly identified as %sprime.\n", line_number, prime, (is_probably_prime ? "composite" : ""));
            error_count++;
        }

        line_number++;
    }

    fclose(file);

    printf("Validation complete. Total errors: %d\n", error_count);

    return 0;
}



// int main()
// {
//     int input_number = 2147483647;  // Change this to the desired input number

//     clock_t start_time = clock();  // Record the start time

//     int result = ft_is_prime(input_number, 1);  // Call the function

//     clock_t end_time = clock();  // Record the end time

//     double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;  // Calculate time taken in seconds

//     // Print the result and time taken
//     printf("Is %d prime? %s\n", input_number, result ? "Yes" : "No");
//     printf("Time taken: %f seconds\n", time_taken);
// }

// int main() {
//     long long number = 2147483647;
//     int iterations = 1;

//     // printf("Enter a number: ");
//     // scanf("%lld", &number);

//     if (number & 1) {
//         // printf("Enter the number of iterations for Miller-Rabin test: ");
//         // scanf("%d", &iterations);

//         if (is_prime_miller_rabin(number, iterations))
//             printf("%lld is probably a prime number.\n", number);
//         else
//             printf("%lld is composite.\n", number);
//     } else {
//         if (number == 2)
//             printf("2 is prime.\n");
//         else
//             printf("%lld is even and not prime.\n", number);
//     }

//     return 0;
// }
