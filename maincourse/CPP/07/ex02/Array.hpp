#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>


/**
 * @brief Class Templates: Similar to function templates but used for classes.
 * Allows you to define a blueprint for a class that can handle any data type.
*/
template <typename T>
class Array {
private:
    T* elements;
    size_t size_;

public:
    // Default constructor
    // This constructor initializes an empty array with no elements, setting elements to NULL and size_ to 0.
    Array() : elements(0), size_(0) {}

    // Constructor with size
    // This constructor creates an array with n elements.
    // Each element is initialized to 0 (for fundamental types) or
    // using the default constructor (for class types).
    // If you allocate fundamental/scalar types with value initialization (using new T[n](), each element of the array is initialized to zero.
    // If T is a class type, new T[n]() will call the default constructor of the class for each element of the array.
    Array(unsigned int n) : elements(new T[n]()), size_(n) {}

    // Copy constructor
    // The copy constructor performs a deep copy of other's data.
    // It allocates a new array and then copies each element from the other array.
    // This ensures that the new Array object has its own separate copy of the data.
    Array(const Array& other) : elements(new T[other.size_]), size_(other.size_) {
        for (size_t i = 0; i < size_; i++) {
            elements[i] = other.elements[i];
        }
    }

    // Destructor
    ~Array() {
        delete[] elements;
    }

    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] elements; // free old memory
            size_ = other.size_;
            elements = new T[size_];
            for (size_t i = 0; i < size_; i++) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    // Subscript Operators
    // The subscript operator purpose is to allow access elements by their index position.
    // The non-const version returns a reference to an element, allowing you to modify the element if needed.
    T& operator[](size_t index) {
        if (index >= size_ || index < 0) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    // The const version is used when the object itself is const.
    // It returns a const reference, preventing modification of the element.
    const T& operator[](size_t index) const {
        // The check index >= size_ ensures the index is not beyond the last element.
        // For siez_t we don't need to check index < 0 but if you decide to change type you will need this check.
        if (index >= size_ || index < 0) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index]; // If the index is valid, the operator returns a reference to the element:
        // Returning a reference avoids copying the element, making access fast.
    }

    // Size Method
    // The size() method in your Array class template is designed to provide users with a way to retrieve the size of the array.
    // const keyword tells that it's read only
    size_t size() const {
        return size_;
    }
};

#endif
