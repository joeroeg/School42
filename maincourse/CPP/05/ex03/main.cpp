#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* unknown_form = NULL;
    AForm* shrubbery_form;
    AForm* robotomy_form;
    AForm* presidential_form;

    shrubbery_form = someRandomIntern.makeForm("shrubbery creation", "Bender");
    if (shrubbery_form) {
        std::cout << "Created a " << shrubbery_form->getName() << std::endl;
        delete shrubbery_form;
    }

    robotomy_form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (robotomy_form) {
        std::cout << "Created a " << robotomy_form->getName() << std::endl;
        delete robotomy_form;
    }

    presidential_form = someRandomIntern.makeForm("presidential pardon", "Bender");
    if (presidential_form) {
        std::cout << "Created a " << presidential_form->getName() << std::endl;
        delete presidential_form;
    }

    unknown_form = someRandomIntern.makeForm("unknown form", "Bender");
    if (unknown_form) {
        std::cout << "Created a " << unknown_form->getName() << std::endl;
        delete unknown_form;
    }
    return 0;
}
