#include "PmergeMe.hpp"

int main(int argc, const char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./pmergeMe [num1] [num2] [num3] ..." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    for (int i = 1; i < argc; i++) {
        vec.push_back(atoi(argv[i]));
    }

    std::cout << "Unsorted vector: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    PmergeMe pmergeMe;
    // vec = pmergeMe.mergeSort(vec);
    pmergeMe.mergeInsertionSort(vec);

    std::cout << "Sorted vector: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
