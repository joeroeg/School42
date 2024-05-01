#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
private:
    T* elements;
    size_t size_;

public:
    // Default constructor
    Array() : elements(NULL), size_(0) {}

    // Constructor with size
    Array(unsigned int n) : elements(new T[n]()), size_(n) {}

    // Copy constructor
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
            delete[] elements;
            size_ = other.size_;
            elements = new T[size_];
            for (size_t i = 0; i < size_; i++) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    // Access elements
    T& operator[](size_t index) {
        if (index >= size_ || index < 0) { // Though size_t is unsigned, adding for clarity
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size_ || index < 0) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    // Get the size of the array
    size_t size() const {
        return size_;
    }
};

class TestClass {
public:
    int value;
    TestClass() : value(0) {}
    TestClass(int v) : value(v) {}
    TestClass(const TestClass& other) : value(other.value) {}

    TestClass& operator=(const TestClass& other) {
        value = other.value;
        return *this;
    }

    // Equality comparison
    bool operator==(const TestClass& other) const {
        return value == other.value;
    }

    // Inequality comparison
    bool operator!=(const TestClass& other) const {
        return value != other.value;
    }
};


#endif
