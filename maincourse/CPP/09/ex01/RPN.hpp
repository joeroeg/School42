#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>

class RPN {
public:
	RPN(void); // default constructor
	RPN(const std::string& str); // parameterized constructor
	RPN(const RPN &src); // copy constructor
	RPN& operator=(RPN const& rhs); // assignment operator
	~RPN(); // destructor
	void calculate(const std::string& str); // calculate the result of the RPN expression

private:
	std::stack<float> _stack; // stack to store the operands

};
bool isNumber(const std::string& s);
bool isOperator(const std::string& s);

#endif
