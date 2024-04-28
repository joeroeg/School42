#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    Bureaucrat alice("Alice", 0);
    Form formA("Form A", 3, 5);

    std::cout << formA << std::endl;

    try {
        formA.beSigned(alice);
        std::cout << formA << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

