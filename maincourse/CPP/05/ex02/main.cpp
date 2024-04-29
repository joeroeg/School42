#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {

    try {
        Bureaucrat admin("Bob", 1);
        ShrubberyCreationForm shrubbery("Shrubbery");
        RobotomyRequestForm robotomy("Robotomy");
        PresidentialPardonForm pardon("President");

        std::cout << "Form 1 Shrubbery" << std::endl;
        shrubbery.beSigned(admin);
        admin.executeForm(shrubbery);
        shrubbery.execute(admin);

        std::cout << "\nForm 2 Robotomy" << std::endl;
        robotomy.beSigned(admin);
        admin.executeForm(robotomy);
        admin.executeForm(robotomy);
        admin.executeForm(robotomy);
        admin.executeForm(robotomy);
        robotomy.execute(admin);

        std::cout << "\nForm 3 President" << std::endl;
        pardon.beSigned(admin);
        admin.executeForm(pardon);
        pardon.execute(admin);

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
