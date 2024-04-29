#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {

    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm form1("Shrubbery");
        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");

        std::cout << "Form 1 Shrubbery" << std::endl;
        form1.beSigned(bob);
        bob.executeForm(form1);
        form1.execute(bob);

        std::cout << "\nForm 2 Robotomy" << std::endl;
        form2.beSigned(bob);
        bob.executeForm(form2);
        bob.executeForm(form2);
        bob.executeForm(form2);
        bob.executeForm(form2);
        form2.execute(bob);

        std::cout << "\nForm 3 President" << std::endl;
        form3.beSigned(bob);
        bob.executeForm(form3);
        form3.execute(bob);

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
