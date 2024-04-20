#include "Cat.hpp"

// Constructor
Cat::Cat() : Animal("Cat") {
    std::cout << "Cat constructor called, type set to: " << type << std::endl;
}

// Destructor
Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat &copy) {
    *this = copy;
}

// Assignation operator
Cat &Cat::operator=(const Cat &copy) {
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

// Make sound
void Cat::makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
}
