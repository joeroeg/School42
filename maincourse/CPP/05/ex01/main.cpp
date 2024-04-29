#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {

    try {
        Bureaucrat alice("Alice", 3);
        Bureaucrat bob("Bob", 5);
        Form formA("Form A", 3, 5);
        std::cout << formA << std::endl;

        std::cout << alice << std::endl;
        formA.beSigned(alice);
        std::cout << formA << std::endl;

        std::cout << bob << std::endl;
        formA.beSigned(bob);
        std::cout << formA << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
