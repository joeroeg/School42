#include <iostream>
#include "Fixed.hpp"

int main() {
    Fixed a;        // Instantiates 'a' using the default constructor
    Fixed b(a);     // Instantiates 'b' by copying 'a' using the copy constructor
    Fixed c;        // Instantiates 'c' using the default constructor

    c = b;          // Assigns 'b' to 'c' using the copy assignment operator

    std::cout << a.getRawBits() << std::endl;  // Calls getRawBits() on 'a'
    std::cout << b.getRawBits() << std::endl;  // Calls getRawBits() on 'b'
    std::cout << c.getRawBits() << std::endl;  // Calls getRawBits() on 'c'

    return 0;       // As 'a', 'b', and 'c' go out of scope, their destructors are called
}
