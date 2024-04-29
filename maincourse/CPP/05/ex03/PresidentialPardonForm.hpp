#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm {
private:
    const std::string   _target;

public:
    // Coplien form
    PresidentialPardonForm(const std::string& target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm&  operator=(const PresidentialPardonForm& rhs);

    // Methods
    void execute(Bureaucrat const & executor) const;
};

#endif
