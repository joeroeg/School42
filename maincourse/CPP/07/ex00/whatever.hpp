#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>


/*
    template <typename T>
    void functionName(T param) {
        // function body
    }
*/
/**
 * @param template keyword: Signals the start of a template definition.
 * @param <typename T>: A template parameter list enclosed in angle brackets (<>).
 * Here, typename (or class, interchangeably used) indicates that T is a type placeholder. This placeholder will be replaced by a concrete type when the template is instantiated.
 * @param T param: The function parameter of type T. You can use T as you would use any other data type.
*/
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(const T& a, const T& b) {
    return (b < a) ? b : a;
}

template <typename T>
T max(const T& a, const T& b) {
    return (a < b) ? b : a;
}

#endif
