#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

class Intern {
private:
    AForm* createShrubberyForm(const std::string& target);
    AForm* createRobotomyForm(const std::string& target);
    AForm* createPresidentialForm(const std::string& target);

public:
    // Coplien form
    Intern();
    ~Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& rhs);

    // Methods
    AForm* makeForm(const std::string& formName, const std::string& target); // makeForm - is a factory method pattern (it identifies input string and create a type)
};

#endif
