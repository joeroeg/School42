#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, 145, 137) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        // This will trigger base class assignment operator
        // This ensures that all base class properties are correctly copied from rhs to this
        // This maintain the integrity of the object's state.
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }
    else if (!isSigned()) {
        throw NotSignedException();
    }
    std::ofstream file(getName() + "_form");
    file << "     *\n";
    file << "    * *\n";
    file << "   *   * \n";
    file << "  *     * \n";
    file << " *       * \n";
    file << "*********** \n";
    file << "    || \n";
    file << "    || \n";
    file << "    || \n";
    file.close();
}

