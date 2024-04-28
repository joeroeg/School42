#include "Form.hpp"

Form::Form(const std::string& name, unsigned int gradeToSign, unsigned int gradeToExecute)
    : _name(name), _isSigned(false), _gradeRequiredToSign(gradeToSign), _gradeRequiredToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150) throw GradeTooLowException();
}

const std::string& Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _isSigned;
}

unsigned int Form::getGradeToSign() const {
    return _gradeRequiredToSign;
}

unsigned int Form::getGradeToExecute() const {
    return _gradeRequiredToExecute;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeRequiredToSign) {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName() << ", form status: " << (f.isSigned() ? "signed" : "not signed")
       << ", grade required to sign: " << f.getGradeToSign()
       << ", grade required to execute: " << f.getGradeToExecute();
    return os;
}
