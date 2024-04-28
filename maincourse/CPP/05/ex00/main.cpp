#include "Bureaucrat.hpp"
#include <iostream>

/**
 * @brief This exercise primarily focuses on using exceptions to manage errors.
 *
 * What are Exceptions?
 * Exceptions are a mechanism for handling runtime errors or unusual conditions in a program.
 * They provide a way to transfer control from one part of a program to another when an error occurs.
 *
 * Why Use Exceptions?
 * Using exceptions allows a program to handle errors gracefully without crashing or producing incorrect results.
 * They also keep error handling code separate from the normal flow of the program, making the code cleaner and easier to manage.
*/

void testTryCatch() {
    try {
        Bureaucrat high("Alice", 1);
        std::cout << high << std::endl;
        high.incrementGrade();  // Exception: Grade too high
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat low("Bob", 150);
        std::cout << low << std::endl;
        low.decrementGrade();  // Exception: Grade too low
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testCopyAssignment() {
    Bureaucrat original("Alice", 1);
    Bureaucrat assignment("Bob", 150);
    Bureaucrat copy = original;
    copy = assignment;

    std::cout << "Original: Name = " << original.getName() << ", Grade = " << original.getGrade() << std::endl;
    std::cout << "Copy: Name = " << copy.getName() << ", Grade = " << copy.getGrade() << std::endl;
    std::cout << "Assignment: Name = " << assignment.getName() << ", Grade = " << assignment.getGrade() << std::endl;
}

int main() {
    testTryCatch();
    testCopyAssignment();
    return 0;
}
