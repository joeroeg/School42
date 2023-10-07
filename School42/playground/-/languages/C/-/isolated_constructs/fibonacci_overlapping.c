/*
https://en.wikipedia.org/wiki/Overlapping_subproblems 
*/

#include <stdio.h>

#define N 10

static int fibMem[N];

int fibonacci(int n) {
	int r = 1;
	if (n > 2) {
		r = fibonacci(n - 1) + fibonacci(n - 2);
	}
	fibMem[n - 1] = r;
	return r;
}

void printFibonacci() {
	int i;
    for (i = 1; i <= N; i++) {
        printf("fibonacci(%d): %d\n", i, fibMem[i - 1]);
    }
}

int main(void) {
    fibonacci(N);
	printFibonacci();
	return 0;
}