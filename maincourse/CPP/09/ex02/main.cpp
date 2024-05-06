#include "PmergeMe.hpp"



void sortAndTime(IntVector& container) {
    timeval tStart, tEnd;
    gettimeofday(&tStart, NULL);
    PmergeMe pmergeMe;
    container = pmergeMe.mergeSort(container, 0);
    gettimeofday(&tEnd, NULL);
    double tVec = static_cast<double>(tEnd.tv_sec - tStart.tv_sec) * 1000000 + static_cast<double>(tEnd.tv_usec - tStart.tv_usec);
    std::cout << "After: ";
    for (IntVector::iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << container.size() << " elements with std::vector: ";
    std::cout << std::fixed << std::setprecision(0) << tVec << " µs";

}

void sortAndTime(IntDeque& container) {
    timeval tStart, tEnd;
    gettimeofday(&tStart, NULL);
    PmergeMe pmergeMe;
    container = pmergeMe.mergeSort(container, 0);
    gettimeofday(&tEnd, NULL);
    double tDeque = static_cast<double>(tEnd.tv_usec - tStart.tv_usec);
    std::cout << std::endl;
    std::cout << "Time to process a range of " << container.size() << " elements with std::deque: "
              << std::fixed << std::setprecision(0) << tDeque << " µs" << std::endl;
}

bool isValidPositiveInteger(const char* str) {
    if (*str == '\0') {
        return false;
    }

    while (*str) {
        if (!isdigit(*str)) {
            return false;
        }
        str++;
    }

    return true;
}

int main(int argc, const char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./pmergeMe [num1] [num2] [num3] ..." << std::endl;
        return 1;
    }

    IntVector vec;
    IntDeque deq;

    for (int i = 1; i < argc; i++) {
        if (!isValidPositiveInteger(argv[i])) {
            std::cerr << "Invalid input: " << argv[i] << std::endl;
            return 1;
        }

        int num = atoi(argv[i]);
        if (num < 0) {
            std::cerr << "Negative numbers are not allowed: " << num << std::endl;
            return 1;
        }

        vec.push_back(num);
        deq.push_back(num);
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }

    std::cout << std::endl;
    sortAndTime(vec);
    sortAndTime(deq);

    return 0;
}
