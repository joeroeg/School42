#include "Fixed.hpp"

// Static member initialization
Fixed::Fixed() : _fixed_point_value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructors with int
Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _fixed_point_value = value << _fractional_bits;
}

// Constructors with float
Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _fixed_point_value = roundf(value * (1 << _fractional_bits));
}

// Copy constructor
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixed_point_value = other._fixed_point_value;
    }
    return *this;
}

// Output stream operator
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Member functions
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixed_point_value;
}

// Member functions
void Fixed::setRawBits(int const raw) {
    _fixed_point_value = raw;
}

// Member functions
float Fixed::toFloat(void) const {
    return (float)_fixed_point_value / (1 << _fractional_bits);
}

// Member functions
int Fixed::toInt(void) const {
    return _fixed_point_value >> _fractional_bits;
}

// Static member functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return a < b ? a : b;
}

// Static member functions
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return a < b ? a : b;
}

// Static member functions
Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return a > b ? a : b;
}

// Static member functions
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return a > b ? a : b;
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const {
    return this->_fixed_point_value > other._fixed_point_value;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_fixed_point_value < other._fixed_point_value;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_fixed_point_value >= other._fixed_point_value;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_fixed_point_value <= other._fixed_point_value;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_fixed_point_value == other._fixed_point_value;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_fixed_point_value != other._fixed_point_value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

/**
 * @brief Prefix increment operator
 * The prefix increment operator is the simplest operator to overload.
 * The prefix increment operator simply increments the value of the object and returns the object.
 * The prefix increment operator returns a reference to the object.
*/
Fixed &Fixed::operator++() {
    this->_fixed_point_value++;  // Increment the internal fixed-point value by one.
    return *this;                // Return a reference to the current object.
}


/**
 * @brief Postfix increment operator
 * The postfix increment operator is a bit more complicated than the prefix increment operator.
 * The postfix increment operator must return the original value of the object, and then increment the value.
 * To do this, we create a temporary object, copy the current object into it, increment the current object, and return the temporary object.
 * The temporary object is created using the copy constructor.
 * The postfix increment operator takes an int parameter to differentiate it from the prefix increment operator.
 * The int parameter is not used in the function.
 * The int parameter is used to differentiate the postfix increment operator from the prefix increment operator.
*/
Fixed Fixed::operator++(int) {
    Fixed tmp(*this);     // Create a copy of the current object using the copy constructor.
    this->operator++();   // Use the prefix increment to increment the current object.
    return tmp;           // Return the temporary object, which holds the old value.
}


// Prefix decrement operator
Fixed &Fixed::operator--() {
    this->_fixed_point_value--;
    return *this;
}git@vogsphere.42quebec.com:vogsphere/intra-uuid-b0d0d649-4562-4c2d-a85e-8f434477db7a-5638639-hezhukovgit@vogsphere.42quebec.com:vogsphere/intra-uuid-b0d0d649-4562-4c2d-a85e-8f434477db7a-5638639-hezhukovgit@vogsphere.42quebec.com:vogsphere/intra-uuid-b0d0d649-4562-4c2d-a85e-8f434477db7a-5638639-hezhukov

// Postfix decrement operator
Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}
