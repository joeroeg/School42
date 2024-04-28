#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
private:
    const std::string _name;
    bool _isSigned;
    const unsigned int _gradeRequiredToSign;
    const unsigned int _gradeRequiredToExecute;

public:
    Form(const std::string& name, unsigned int gradeToSign, unsigned int gradeToExecute);
    ~Form() {}
    Form(const Form& other);
    Form& operator=(const Form& rhs);

    const std::string& getName() const;
    bool isSigned() const;
    unsigned int getGradeToSign() const;
    unsigned int getGradeToExecute() const;

    void beSigned(const Bureaucrat& b);

    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw() {
            return "Grade too high for form";
        }
    };

    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw() {
            return "Grade too low for form";
        }
    };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
