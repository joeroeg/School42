#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
    const std::string _name;
    unsigned int _grade;
    // Bureaucrat();

public:
    // Coplien form
    Bureaucrat(const std::string& name, unsigned int grade); // Constructor
    ~Bureaucrat();                                           // Descturcor
    Bureaucrat(const Bureaucrat& other);                     // Copy constructor
    Bureaucrat& operator=(const Bureaucrat& rhs);            // Assignment operator

    // Methods
    const std::string& getName() const;
    unsigned int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    virtual void executeForm(AForm const & executor);

    // Exceptions
    class GradeTooHighException : public std::exception {
        // std::exception has a virtual method called what() that returns a C-style string (const char*) describing the exception.
        // In modern C++, you should use noexcept instead of throw(). It provides better performance optimizations by the compiler.
        // const char* what() const noexcept override { return "Grade too high"; }
        virtual const char* what() const throw() {
            return "Grade too high";
        }
    };

    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw() {
            return "Grade too low";
        }
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
