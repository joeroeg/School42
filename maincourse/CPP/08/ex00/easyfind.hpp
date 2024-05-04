#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stdexcept>
#include <algorithm>

/*
Iterators are a fundamental concept in C++ that provide a way to access and traverse elements in a container like
(arrays, vectors, lists, etc.) without exposing the underlying implementation details of the container.

Here are the key points about iterators:
1. Abstraction:
   - Iterators abstract the traversal of a container, allowing generic access to elements.
   - They hide the underlying container's implementation details.
2. Traversal:
   - Iterators provide operations to move through elements (e.g., ++it, it++).
   - Different types of iterators allow different traversal capabilities.
3. Compatibility:
   - Iterators work with various containers and algorithms.
   - Containers provide iterators tailored to their characteristics.
4. Validity:
   - Iterators can become invalid if the container is modified.
   - Invalid iterators should not be used.
5. Types:
   - Types of iterators (e.g., input, output, forward, bidirectional, random access) offer different functionality.
   - Each type has specific operations it supports.
6. Syntax:
   - Iterators are used like pointers (e.g., *it to dereference, ++it or it++ to move).
   - They offer a pointer-like interface for working with elements.
*/

/**
 * @brief The easyfind function searches for a value in a container and returns an iterator to the first occurrence of the value.
 * @param typename T::iterator: typename is used to declare a dependent type. In this case, T::iterator is a dependent type because it depends on the template parameter T.
 * @param std::find Algorithm: The std::find algorithm iterates over the range [container.begin(), container.end()) and returns an iterator pointing to the first element in the range that is equal to value. If no such element is found, it returns container.end().
 * @param container.begin() Returns an iterator pointing to the beginning of the container T.
 * @param container.end() Returns an iterator pointing to the end of the container T.
 * @note This function could be used with various sequence containers like vector, list, and deque.
*/
template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found");
    }
    return it;
}

// Map is a sorted associative container that contains key-value pairs.
// The easyfindMap function searches for a key in a map and returns an iterator to the key-value pair.
// Because map is pointing to a pair, we need to use it->first to access the key and it->second to access the value.
template <typename T>
typename T::iterator easyfindMap(T &container, int value) {
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        if (it->first == value) {
            return it;
        }
    }
    throw std::runtime_error("Value not found");
}

#endif
