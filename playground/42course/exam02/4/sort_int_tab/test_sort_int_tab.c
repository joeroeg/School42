#include <stdio.h>
#include <stdbool.h>

// Your sort_int_tab function
void sort_int_tab(int *tab, unsigned int size);

// Function to print the array (for testing)
void print_array(int *array, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to check if the array is sorted
bool is_sorted(int *array, unsigned int size) {
    for (unsigned int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    unsigned int size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    print_array(array, size);

    sort_int_tab(array, size);

    // After sorting the array in the test program
    printf("Sorted array:\n");
    for (unsigned int i = 0; i < size; i++) {
    printf("%d\n", array[i]); // Print each element on a new line
    }


    if (is_sorted(array, size)) {
        printf("The array is correctly sorted.\n");
    } else {
        printf("The array is not correctly sorted.\n");
    }

    return 0;
}
