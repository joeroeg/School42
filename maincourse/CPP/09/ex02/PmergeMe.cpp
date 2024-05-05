#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
    // std::cout << "Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(int argc, const char **argv) {
    // std::cout << "Constructor called" << std::endl;
    for (int i = 1; i < argc; i++) {
        _vec.push_back(atoi(argv[i]));
    }
}

PmergeMe::~PmergeMe() {
    // std::cout << "Destructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
    // std::cout << "Assignment operator called" << std::endl;
    if (this != &rhs) {
        _vec = rhs._vec;
    }
    return *this;
}

/*
IntVector PmergeMe::merge(const IntVector& left, const IntVector& right) {
    IntVector result;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

IntVector PmergeMe::mergeSort(IntVector& vec) {
    const size_t threshold = 500; // Threshold for switching to insertion sort
    if (vec.size() <= 1) {
        return vec;
    }

    if (vec.size() <= threshold) {
        std::cout << "Using Insertion Sort for subsequence of size " << vec.size() << std::endl;
        insertionSort(vec);
        return vec;
    }

    std::cout << "Using Merge Sort for subsequence of size " << vec.size() << std::endl;
    size_t middle = vec.size() / 2;
    IntVector left(vec.begin(), vec.begin() + middle);
    IntVector right(vec.begin() + middle, vec.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}


void PmergeMe::insertionSort(IntVector& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        size_t j = i;

        while (j > 0 && vec[j - 1] > key) {
            vec[j] = vec[j - 1];
            j--;
        }

        vec[j] = key;
    }
}
*/


void PmergeMe::merge(IntVector& vec, size_t start, size_t mid, size_t end) {
    IntVector temp(end - start + 1);
    size_t i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end) {
        if (vec[i] <= vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = vec[i++];
    }

    while (j <= end) {
        temp[k++] = vec[j++];
    }

    for (i = 0; i < k; ++i) {
        vec[start + i] = temp[i];
    }
}

void PmergeMe::mergeSort(IntVector& vec, size_t start, size_t end) {
    // std::cout << "Using Merge Sort for subsequence of size " << end - start + 1 << std::endl;
    if (start < end) {
        size_t mid = start + (end - start) / 2;
        mergeSort(vec, start, mid);
        mergeSort(vec, mid + 1, end);
        merge(vec, start, mid, end);
    }
}

void PmergeMe::insertionSort(IntVector& vec) {
    std::cout << "Using Insertion Sort for subsequence of size " << vec.size() << std::endl;
    for (size_t i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        size_t j = i;

        while (j > 0 && vec[j - 1] > key) {
            vec[j] = vec[j - 1];
            j--;
        }

        vec[j] = key;
    }
}

void PmergeMe::mergeInsertionSort(IntVector& vec) {
    mergeSort(vec, 0, vec.size() - 1);

    // Check if the entire sequence is sorted
    bool isSorted = true;
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i - 1] > vec[i]) {
            isSorted = false;
            break;
        }
    }

    std::cout << "isSorted: " << isSorted << std::endl; // "isSorted: 1" or "isSorted: 0
    // If not sorted, use insertion sort
    if (!isSorted) {
        insertionSort(vec);
    }
}
