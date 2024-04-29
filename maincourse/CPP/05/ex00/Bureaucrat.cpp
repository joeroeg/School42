#include "Bureaucrat.hpp"
#include <iostream>

// Constructor
Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name), _grade(grade) {
    if (grade < 1) throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

// This approach won't work because it won't copy const _name (because it's const), so we need to use a list initializer instead.
// Bureaucrat::Bureaucrat(const Bureaucrat& other) {
//     *this = other;
// }

// Assignment operaotor
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
    if (this != &rhs)
        _grade = rhs._grade;
    return *this;
}

const std::string& Bureaucrat::getName() const { return _name; }
unsigned int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
