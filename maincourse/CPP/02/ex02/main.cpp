#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    // Additional tests
    Fixed c(42.42f);
    Fixed d(21.21f);
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "c + d: " << c + d << std::endl;
    std::cout << "c - d: " << c - d << std::endl;
    std::cout << "c * d: " << c * d << std::endl;
    std::cout << "c / d: " << c / d << std::endl;
    std::cout << "c > d: " << (c > d) << std::endl;
    std::cout << "c < d: " << (c < d) << std::endl;
    std::cout << "c >= d: " << (c >= d) << std::endl;
    std::cout << "c <= d: " << (c <= d) << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "c != d: " << (c != d) << std::endl;
    std::cout << "c min d: " << Fixed::min(c, d) << std::endl;
    std::cout << "c max d: " << Fixed::max(c, d) << std::endl;


    // 2^-8 = 0.00390625
    Fixed e;
    std::cout << "Original e: " << e << std::endl;
    std::cout << "Using postfix e++: " << e++ << std::endl;
    std::cout << "After postfix e++: " << e << std::endl;

    Fixed f;
    std::cout << "Original f: " << f << std::endl;
    std::cout << "Using prefix ++f: " << ++f << std::endl;
    std::cout << "After prefix ++f: " << f << std::endl;

    return 0;
}
