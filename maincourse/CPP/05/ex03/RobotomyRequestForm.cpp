#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", 72, 45), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        // This will trigger base class assignment operator
        // This ensures that all base class properties are correctly copied from rhs to this
        // This maintain the integrity of the object's state.
    }
    return *this;
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }
    else if (!isSigned()) {
        throw NotSignedException();
    } else {
        std::cout << "Drilling noises... \n";
        static int i;
        if (i % 2 == 0 )
            std::cout << _target << " has been robotomized successfully" << std::endl;
        else
            std::cout << "Robotomy failed! " << _target << " is still alive." << std::endl;
        i++;
    }
}
