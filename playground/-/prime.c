#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

void sieve_of_eratosthenes(int limit, int* primes) {
    int i, j;
    char* is_prime = (char*)malloc((limit + 1) * sizeof(char));

    // Initialize all numbers as prime
    for (i = 0; i <= limit; i++)
        is_prime[i] = 1;

    is_prime[0] = is_prime[1] = 0;

    for (i = 2; i <= sqrt(limit); i++) {
        if (is_prime[i]) {
            for (j = i * i; j <= limit; j += i)
                is_prime[j] = 0;
        }
    }

    int count = 0;
    for (i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes[count] = i;
            count++;
        }
    }

    free(is_prime);
}

int main() {
    const int num_to_check = 1000000;
    int* primes = (int*)malloc(num_to_check * sizeof(int));

    clock_t start_time = clock();

    sieve_of_eratosthenes(num_to_check, primes);

    clock_t end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Number of prime numbers from 1 to %d: %d\n", num_to_check, num_to_check > 1 ? primes[num_to_check - 1] : 0);
    printf("Time taken: %f seconds\n", time_taken);
    free(primes);
    


    return 0;
}


// int is_prime(int num) {
//     if (num < 2)
//         return 0;

//     int max_divisor = (int)sqrt(num);
//     for (int i = 2; i <= max_divisor; i++) {
//         if (num % i == 0)
//             return 0;
//     }

//     return 1;
// }

// int is_prime(int num) {
//     if (num < 2)
//         return 0;

//     if (num == 2 || num == 3)
//         return 1;

//     if (num % 2 == 0 || num % 3 == 0)
//         return 0;

//     int max_divisor = (int)sqrt(num);
//     for (int i = 5; i <= max_divisor; i += 6) {
//         if (num % i == 0 || num % (i + 2) == 0)
//             return 0;
//     }

//     return 1;
// }

// int main() {
//     const int num_to_check = 100000000;

//     clock_t start_time = clock();

//     int prime_count = 0;
//     for (int i = 1; i <= num_to_check; i++) {
//         if (is_prime(i))
//             prime_count++;
//     }

//     clock_t end_time = clock();

//     double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

//     printf("Number of prime numbers from 1 to %d: %d\n", num_to_check, prime_count);
//     printf("Time taken: %f seconds\n", time_taken);

//     return 0;
// }
