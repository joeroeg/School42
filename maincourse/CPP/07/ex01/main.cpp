#include "iter.hpp"

void increment(int& n) {
    ++n;
}

void doubleValue(int& n) {
    n *= 2;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t arr_length = sizeof(arr) / sizeof(arr[0]);

    iter(arr, arr_length, increment);

    for (size_t i = 0; i < arr_length; ++i) {
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl;

    iter(arr, arr_length, doubleValue);

    for (size_t i = 0; i < arr_length; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}


