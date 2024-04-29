#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>

class RobotomyRequestForm : public AForm {
private:
    const std::string   _target;

public:
    // Coplien form
    RobotomyRequestForm(const std::string& target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm&  operator=(const RobotomyRequestForm& rhs);

    // Methods
    void execute(Bureaucrat const & executor) const;
};

#endif
