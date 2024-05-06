#include "PmergeMe.hpp"

#define THRESHOLD 5

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


// Vector sort
IntVector PmergeMe::merge(const IntVector& left, const IntVector& right) {
    IntVector result;
    size_t i = 0, j = 0;

    // std::cout << "Merging arrays:" << std::endl;
    // std::cout << "Left array: ";
    // for (size_t k = 0; k < left.size(); ++k) {
    //     std::cout << left[k] << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "Right array: ";
    // for (size_t k = 0; k < right.size(); ++k) {
    //     std::cout << right[k] << " ";
    // }
    // std::cout << std::endl;

    // Merge the two arrays
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    // Add the remaining elements from the left and right arrays
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }

    // Add the remaining elements from the right array
    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    // std::cout << "Merged array: ";
    // for (size_t k = 0; k < result.size(); ++k) {
    //     std::cout << result[k] << " ";
    // }
    // std::cout << std::endl;

    return result;
}


IntVector PmergeMe::mergeSort(IntVector& vec, size_t depth) {
    // Threshold for using insertion sort
    const size_t threshold = THRESHOLD;
    if (vec.size() <= 1) {
        return vec;
    }

    // If the size of the subarray is less than or equal to the threshold, use insertion sort
    if (vec.size() <= threshold) {
        // std::cout << "Using Insertion Sort for subsequence of size " << vec.size() << std::endl;
        insertionSort(vec);
        return vec;
    }

    // std::cout << "Using Merge Sort for subsequence of size " << vec.size() << " at depth " << depth << std::endl;
    size_t middle = vec.size() / 2;
    IntVector left(vec.begin(), vec.begin() + middle);
    IntVector right(vec.begin() + middle, vec.end());

    // print values of left and right
    // std::cout << "Left array: ";
    // for (size_t k = 0; k < left.size(); ++k) {
    //     std::cout << left[k] << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "Right array: ";
    // for (size_t k = 0; k < right.size(); ++k) {
    //     std::cout << right[k] << " ";
    // }
    // std::cout << std::endl;
    // std::cout << std::endl;

    left = mergeSort(left, depth + 1);
    right = mergeSort(right, depth + 1);

    return merge(left, right);
}


/**
 * @param i - index of the element to be inserted. We start from the second element because the first element is already sorted.
 * @param key - This element will be compared and inserted into its correct position in the sorted subarray.
 * @param j - It is used to iterate backwards through the sorted subarray to find the correct position for the key element.
*/
void PmergeMe::insertionSort(IntVector& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        size_t j = i;

        // std::cout << "Key: " << key << ", ";
        // std::cout << "i: " << i << ", ";
        // std::cout << "j: " << j << std::endl;

        while (j > 0 && vec[j - 1] > key) {
            vec[j] = vec[j - 1]; // In each iteration, the element at position j - 1 is moved to position j, and j is decremented.
            j--;
            // std::cout << "Shifting element " << vec[j] << " to position " << j + 1 << std::endl;
        }

        vec[j] = key;

        // std::cout << "Inserting key " << key << " at position " << j << std::endl;
        // std::cout << "Current state of the array: ";
        // for (size_t k = 0; k < vec.size(); ++k) {
        //     std::cout << vec[k] << " ";
        // }
    }
}


// Deque sort
IntDeque PmergeMe::merge(const IntDeque& left, const IntDeque& right) {
    IntDeque result;
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

IntDeque PmergeMe::mergeSort(IntDeque& vec, size_t depth) {
    const size_t threshold = THRESHOLD;
    if (vec.size() <= 1) {
        return vec;
    }

    if (vec.size() <= threshold) {
        // std::cout << "Using Insertion Sort for subsequence of size " << vec.size() << std::endl;
        insertionSort(vec);
        return vec;
    }

    // std::cout << "Using Merge Sort for subsequence of size " << vec.size() << std::endl;
    size_t middle = vec.size() / 2;
    IntDeque left(vec.begin(), vec.begin() + middle);
    IntDeque right(vec.begin() + middle, vec.end());

    left = mergeSort(left, depth + 1);
    right = mergeSort(right, depth + 1);

    return merge(left, right);
}


void PmergeMe::insertionSort(IntDeque& vec) {
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
