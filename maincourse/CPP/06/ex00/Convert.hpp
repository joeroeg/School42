#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cmath>
using std::string;
using std::cout;
using std::endl;

class Converter {
private:
	const string	_input;
	double stringToDouble() const;

public:
	Converter(const string input);				// Constructor
	Converter(Converter const& val); 			// Copy constructor
	~Converter(void); 							// Destructor
	Converter& operator=(Converter const& rhs); // Assignment operator

	// Conversion functions
	operator char() const;
	operator int() const;
	operator float() const;
	operator double() const;
};

std::ostream& operator<<(std::ostream& os, Converter& rhs);

#endif
