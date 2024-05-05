#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "iostream"
#include "vector"
#include <deque>

typedef std::vector<int> IntVector;

class PmergeMe {
public:
    PmergeMe(); // default constructor
    PmergeMe(int argc, const char **argv); // constructor
    ~PmergeMe(); // destructor
    PmergeMe(const PmergeMe &src); // copy constructor
    PmergeMe &operator=(PmergeMe const &rhs); // assignment operator

    // Simplified Ford-Johnson merge
    // IntVector merge(const IntVector& left, const IntVector& right);
    // IntVector mergeSort(IntVector& vec);
    // void insertionSort(IntVector& vec);

    // Original Ford-Johnson merge
    void merge(IntVector& vec, size_t start, size_t mid, size_t end);
    void mergeSort(IntVector& vec, size_t start, size_t end);
    void insertionSort(IntVector& vec);
    void mergeInsertionSort(IntVector& vec);

private:
    IntVector _vec;
};

#endif
