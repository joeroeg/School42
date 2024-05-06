#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "iostream"
#include <vector>
#include <deque>
#include <iomanip>
#include <sys/time.h>

typedef std::vector<int> IntVector;
typedef std::deque<int> IntDeque;

class PmergeMe {
public:
    PmergeMe(); // default constructor
    PmergeMe(int argc, const char **argv); // constructor
    ~PmergeMe(); // destructor
    PmergeMe(const PmergeMe &src); // copy constructor
    PmergeMe &operator=(PmergeMe const &rhs); // assignment operator

    // Vector sort
    IntVector merge(const IntVector& left, const IntVector& right);
    IntVector mergeSort(IntVector& vec, size_t depth);
    void insertionSort(IntVector& vec);

    // Deque sort
    IntDeque merge(const IntDeque& left, const IntDeque& right);
    IntDeque mergeSort(IntDeque& deque, size_t depth);
    void insertionSort(IntDeque& deque);

private:
    IntVector _vec;
    IntDeque _deque;
};

#endif
