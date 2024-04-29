#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern& other) {
    *this = other;
    // the copy constructor has nothing to copy because there are no resources to copy.
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {
        // the assignment operator has nothing to assign because there are no resources to assign.
    }
    return *this;
}

/**
 * @note The makeForm method loops through the formNames array to find a match for the formName provided by the user.
 * If a match is found, it uses the corresponding index to call the appropriate factory method from the formCreators array, passing the target to it.
 * This factory method creates and returns an instance of the appropriate form.
 * If no match is found, it outputs an error message and returns nullptr, indicating that no form was created.
*/
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*formCreators[3])(const std::string&) = {
        &Intern::createShrubberyForm,
        &Intern::createRobotomyForm,
        &Intern::createPresidentialForm
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formNames[i] << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    std::cout << "Error: Form name '" << formName << "' is not recognized." << std::endl;
    return NULL;
}


AForm* Intern::createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}
