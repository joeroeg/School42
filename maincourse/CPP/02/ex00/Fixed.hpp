#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
private:
    int _fixed_point_value;                  // The raw value of the fixed point value
    static const int _fractional_bits = 8;   // The number of fractional bits in the fixed point value

public:
    Fixed();                                // Default constructor
    Fixed(const Fixed &other);              // Copy constructor
    Fixed &operator=(const Fixed &other);   // Copy assignment operator
    ~Fixed();                               // Destructor

    int getRawBits(void) const;             // Returns the raw value of the fixed point value
    void setRawBits(int const raw);         // Sets the raw value of the fixed point value
};

#endif
