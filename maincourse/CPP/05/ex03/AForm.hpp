#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _isSigned;
    const unsigned int _gradeRequiredToSign;
    const unsigned int _gradeRequiredToExecute;

public:
    // Coplien form
    AForm(const std::string& name, unsigned int gradeToSign, unsigned int gradeToExecute);
    virtual ~AForm();
    AForm(const AForm& other);
    AForm& operator=(const AForm& rhs);

    // Methods
    const std::string& getName() const;
    bool isSigned() const;
    unsigned int getGradeToSign() const;
    unsigned int getGradeToExecute() const;
    void beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const & executor) const = 0;

    // Exceptions
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

    class NotSignedException : public std::exception {
        const char* what() const throw() {
            return "Form not signed";
        }
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
