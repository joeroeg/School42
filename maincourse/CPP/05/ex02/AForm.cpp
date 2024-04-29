#include "AForm.hpp"

// Constructor
AForm::AForm(const std::string& name, unsigned int gradeToSign, unsigned int gradeToExecute)
    : _name(name), _isSigned(false), _gradeRequiredToSign(gradeToSign), _gradeRequiredToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150) throw GradeTooLowException();
}

// Destructor
AForm::~AForm() {}

// Copy constructor
AForm::AForm( const AForm& src ) : _name( src.getName() ), _gradeRequiredToSign( src.getGradeToSign() ), _gradeRequiredToExecute( src.getGradeToExecute() ) {}

// Assignment operator
AForm&   AForm::operator=( const AForm& rhs ) {
    if ( this != &rhs )
        _isSigned = rhs.isSigned();
    return *this;
}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

unsigned int AForm::getGradeToSign() const {
    return _gradeRequiredToSign;
}

unsigned int AForm::getGradeToExecute() const {
    return _gradeRequiredToExecute;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeRequiredToSign) {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName() << ", AForm status: " << (f.isSigned() ? "signed" : "not signed")
       << ", grade required to sign: " << f.getGradeToSign()
       << ", grade required to execute: " << f.getGradeToExecute();
    return os;
}


