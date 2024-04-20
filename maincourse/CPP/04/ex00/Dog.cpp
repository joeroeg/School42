#include "Dog.hpp"

// Constructor
Dog::Dog() : Animal("Dog") {
    std::cout << "Dog constructor called, type set to: " << type << std::endl;
}

// Destructor
Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog &copy) {
    *this = copy;
}

// Assignation operator
Dog &Dog::operator=(const Dog &copy) {
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

// Make sound
void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}
