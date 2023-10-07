#include <stdio.h>
#include <time.h>

int main()
{
	clock_t start, end;
	double cpu_time_used;

    start = clock();
    float celsius; 
    int fahrenheit;
	float fahrToCelsiusFactor = 5.0 / 9.0;

    celsius = 0;
    fahrenheit = 0;
    
    while (fahrenheit <= 300000000)
    {
		celsius = (fahrenheit - 32) * fahrToCelsiusFactor; // Convert Fahrenheit to Celsius
		printf("F: %3.d C: %6.2f\n", fahrenheit, celsius);
		fahrenheit += 20;
    }
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);
    return (0);
}

// Time taken: 22.625172 seconds - original
// Time taken: 22.520130 seconds - upgraded
// Time taken: 22.091786 seconds - optimization flags
