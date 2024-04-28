#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat alice("Alice", 0);  // This will throw an exception
        Form formA("Form A", 3, 5);

        std::cout << formA << std::endl;

        formA.beSigned(alice);
        std::cout << formA << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Exception caught for Bureaucrat: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << "Exception caught for Bureaucrat: " << e.what() << std::endl;
    } catch (const Form::GradeTooHighException& e) {
        std::cout << "Exception caught for Form: " << e.what() << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cout << "Exception caught for Form: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Other exceptions: " << e.what() << std::endl;
    }

    return 0;
}
