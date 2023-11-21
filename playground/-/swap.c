#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_char(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void swap_int_arrays(int *arr1, int *arr2, size_t len) {
    for (size_t i = 0; i < len; i++) {
        swap_int(&arr1[i], &arr2[i]);
    }
}

void swap_char_arrays(char *str1, char *str2, size_t len) {
    for (size_t i = 0; i < len; i++) {
        swap_char(&str1[i], &str2[i]);
    }
}

void swap_pointers(void *ptr1, void *ptr2, size_t size) {
    char *temp = malloc(size);
    if (temp == NULL) {
        // Handle memory allocation error
        return;
    }

    memcpy(temp, ptr1, size);
    memcpy(ptr1, ptr2, size);
    memcpy(ptr2, temp, size);
    free(temp);
}

void swap_pointers2(void **ptr1, void **ptr2) {
    void *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}


int main() {
    // Swapping integers
    int a = 5, b = 10;
	printf("bfr: %d %d\n", a, b);
    swap_int(&a, &b);
	printf("afr: %d %d\n", a, b);

    // Swapping characters
    char c1 = 'x', c2 = 'y';
	printf("bfr: %c %c\n", c1, c2);
    swap_char(&c1, &c2);
	printf("afr: %c %c\n", c1, c2);

    // Swapping integer arrays
    int arr1[] = {1, 2, 3}, arr2[] = {4, 5, 6};
    for (int i = 0; i < 3; i++) {
        printf("bfr: arr1[%d] = %d, arr2[%d] = %d\n", i, arr1[i], i, arr2[i]);
    }
    swap_int_arrays(arr1, arr2, 3);
	for (int i = 0; i < 3; i++) {
        printf("afr: arr1[%d] = %d, arr2[%d] = %d\n", i, arr1[i], i, arr2[i]);
    }

    // Swapping strings
    char str1[] = "Hello", str2[] = "World";
	printf("bfr: %s %s\n", str1, str2);
    swap_char_arrays(str1, str2, 5);
	printf("afr: %s %s\n", str1, str2);

    // Swapping pointers (generic)
    int *ptr1 = &a, *ptr2 = &b;
    printf("bfr: %p %p\n", ptr1, ptr2);
	swap_pointers(&ptr1, &ptr2, sizeof(int));
	printf("afr: %p %p\n", ptr1, ptr2);

	// Swapping pointers
	int *ptr3 = &a, *ptr4 = &b;
    printf("Before swap: ptr1 points to %d, ptr2 points to %d\n", *ptr3, *ptr4);
    swap_pointers2((void **)&ptr3, (void **)&ptr4);
    printf("After swap: ptr1 points to %d, ptr2 points to %d\n", *ptr3, *ptr4);
    return 0;
}


