#include "Animal.hpp"

// Constructor
Animal::Animal() : type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

// Constructor
Animal::Animal(std::string type) : type(type) {
    std::cout << "Animal created with type: " << type << std::endl;
}

// Destructor
Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal &copy) {
    *this = copy;
}

// Assignation operator
Animal &Animal::operator=(const Animal &copy) {
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

// Getter for type
std::string Animal::getType() const {
    return this->type;
}

// Make sound
void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}
