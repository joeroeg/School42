#pragma once
#include <_stdio.h>
#include <iostream>

enum eType {
	none,
	intValue,
	floatValue,
	doubleValue,
	charValue
};

class Parser
{
private:
	std::string _str;
	int			_type;
	int			_precision;
	int			_intValue;
	float		_floatValue;
	double		_doubleValue;
	char		_charValue;
public:
	// Constructors / Destructor
	Parser();
	Parser(std::string str);
	Parser(const Parser &inst);
	~Parser();

	// Operator Overload
	Parser& operator=(const Parser &rhs);
	operator float();
	operator int();
	operator double();
	operator char();

	// Functions
	void setType();
	void isInt();
	void isFloat();
	void isDouble();
	void isChar();
	void printValue();
};

// Parser_HPP
