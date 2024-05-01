#include "Convert.hpp"

// Coplien form
Converter::Converter(const string src) : _input(src) {}
Converter::Converter(Converter const & src) : _input(src._input) { *this = src; }
Converter::~Converter(void) {}
Converter& Converter::operator=( Converter const & rhs ) { (void)rhs; return *this; }

// Internal methods
double Converter::stringToDouble() const {
	try {
		return std::stod(_input);
	} catch (const std::exception& e) {
		throw std::invalid_argument("Non displayable");
	}
}

// Conversion functions
Converter::operator char() const {
	int value = static_cast<int>(*this);
	if (value < 0 || value > 255 || !std::isprint(static_cast<unsigned char>(value)))
		throw std::out_of_range("Non displayable");
	return static_cast<char>(value);
}

Converter::operator int() const {
	double value = stringToDouble();
	if (isnan(value) || isinf(value))
		throw std::out_of_range("impossible");
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        throw std::out_of_range("Integer overflow");
	return static_cast<int>(value);
}

Converter::operator float() const {
	return static_cast<float>(stringToDouble());
}

Converter::operator double() const {
	return stringToDouble();
}

// Insertion overload
std::ostream& operator<<(std::ostream& os, Converter& rhs) {
    try {
        char convertedChar = static_cast<char>(rhs);
        os << "  char: '" << convertedChar << "'" << endl;
    } catch(const std::exception& e) {
        os << "  char: " << e.what() << std::endl;
    }
	try {
        os << "   int: " << static_cast<int>(rhs) << endl;
    } catch(const std::exception& e) {
        os << e.what() << std::endl;
    }

	try {
        os << " float: " << std::fixed << std::setprecision(1) <<static_cast<float>(rhs) << 'f' << std::endl;
    } catch(const std::exception& e) {
        os << e.what() << endl;
    }

	try {
        os << "double: " << std::fixed << std::setprecision(1) <<static_cast<double>(rhs) << std::endl;
    } catch(const std::exception& e) {
        os << e.what() << endl;
    }
	return (os);
}
