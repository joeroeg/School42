#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("President Request Form", 72, 45), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), _target(src._target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
    }
    return *this;
}

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw AForm::GradeTooLowException();
    else {
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}
