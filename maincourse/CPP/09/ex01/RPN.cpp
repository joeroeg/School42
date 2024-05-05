#include "RPN.hpp"

RPN::RPN(void) { return; } // default constructor
RPN::RPN(const std::string& str) { calculate(str); } // parameterized constructor
RPN::RPN(const RPN &src) { *this = src; } // copy constructor
RPN::~RPN() { return; } // destructor
RPN& RPN::operator=(RPN const& rhs) { // assignment operator
    if (this != &rhs) {
        _stack = rhs._stack;
    }
    return *this;
}


bool isOperator(const std::string& token) { return token == "+" || token == "-" || token == "*" || token == "/";}

bool isNumber(const std::string& token) {
    if (token.empty()) return false;
    for (size_t i = 0; i < token.size(); i++) {
        if (!std::isdigit(token[i]) && token[i] != '.') return false;
    }
    return true;
}

void RPN::calculate(const std::string& str) {
    std::istringstream iss(str);
    std::string token;
    while (std::getline(iss, token, ' ')) {
        if (isOperator(token)) {
            if (_stack.size() < 2) {
                std::cerr << "Error: not enough operands." << std::endl;
                return;
            }
            float a = _stack.top();
            _stack.pop();
            float b = _stack.top();
            _stack.pop();
            if (token == "+") {
                float result = b + a;
                _stack.push(result);
                // std::cout << b << " + " << a << " = " << result << std::endl;
            }
            else if (token == "-") {
                float result = b - a;
                _stack.push(result);
                // std::cout << b << " - " << a << " = " << result << std::endl;
            }
            else if (token == "*") {
                float result = b * a;
                _stack.push(result);
                // std::cout << b << " * " << a << " = " << result << std::endl;
            }
            else if (token == "/") {
                if (a == 0) {
                    std::cerr << "Error: division by zero." << std::endl;
                    return;
                }
                float result = b / a;
                _stack.push(result);
                // std::cout << b << " / " << a << " = " << result << std::endl;
            }
        }
        else if (isNumber(token)) {
            float num;
            std::istringstream(token) >> num;
            _stack.push(num);
            // std::cout << "Pushed: " << num << std::endl;
        } else {
                std::cerr << "Error: invalid token." << std::endl;
                return;
            }
        }
    if (_stack.size() != 1) {
        std::cerr << "Error: invalid expression." << std::endl;
        return;
    }
    std::cout << _stack.top() << std::endl;
    return;
}

