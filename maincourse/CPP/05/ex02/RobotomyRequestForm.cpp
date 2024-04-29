#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", 72, 45), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
    }
    return *this;
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!isSigned() || executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
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
