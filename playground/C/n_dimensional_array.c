#include <stdio.h>
#include <stdlib.h>

// Structure to represent an N-dimensional array
typedef struct {
    int* data;
    int* dimensions;
    int n;
} NDArray;

// Function to create an N-dimensional array
NDArray* createNDArray(int n, int* dimensions) {
    NDArray* array = (NDArray*)malloc(sizeof(NDArray));
    array->n = n;
    array->dimensions = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array->dimensions[i] = dimensions[i];
    }

    int size = 1;
    for (int i = 0; i < n; i++) {
        size *= dimensions[i];
    }

    array->data = (int*)malloc(size * sizeof(int));

    return array;
}

// Function to access an element of the N-dimensional array
int getNDArray(NDArray* array, int* indices) {
    int index = 0;
    int stride = 1;
    for (int i = array->n - 1; i >= 0; i--) {
        index += indices[i] * stride;
        stride *= array->dimensions[i];
    }

    return array->data[index];
}

// Function to set an element of the N-dimensional array
void setNDArray(NDArray* array, int* indices, int value) {
    int index = 0;
    int stride = 1;
    for (int i = array->n - 1; i >= 0; i--) {
        index += indices[i] * stride;
        stride *= array->dimensions[i];
    }

    array->data[index] = value;
}

void initializeArray(NDArray* array, int* indices, int dimension, int* value) {
    if (dimension == array->n) {
        setNDArray(array, indices, (*value)++);
    } else {
        for (int i = 0; i < array->dimensions[dimension]; i++) {
            indices[dimension] = i;
            initializeArray(array, indices, dimension + 1, value);
        }
    }
}

// Helper function to recursively print the array
void printArray(NDArray* array, int* indices, int dimension) {
    if (dimension == array->n) {
        printf("%d ", getNDArray(array, indices));
    } else {
        for (int i = 0; i < array->dimensions[dimension]; i++) {
            indices[dimension] = i;
            printArray(array, indices, dimension + 1);
            if (dimension == array->n - 2) printf("\n");
            if (dimension == array->n - 3) printf("\n\n");
        }
    }
}

int main() {
    int n = 4;                          // Number of dimensions
    int dimensions[] = {3, 5, 10, 4};   // Size of each dimension

    NDArray* array = createNDArray(n, dimensions);

    int* indices = (int*)malloc(n * sizeof(int));
    int value = 0;
    initializeArray(array, indices, 0, &value);

    printf("N-dimensional array:\n");
    printArray(array, indices, 0);

    free(indices);
    free(array->data);
    free(array->dimensions);
    free(array);

    return 0;
}
