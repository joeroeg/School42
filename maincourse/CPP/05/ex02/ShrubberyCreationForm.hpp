#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    const std::string   _target;

public:
    // Coplien form
    ShrubberyCreationForm(const std::string& target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm&  operator=(const ShrubberyCreationForm& rhs);

    // Methods
    void execute(Bureaucrat const & executor) const;
};

#endif
