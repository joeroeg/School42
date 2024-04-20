#include "Cat.hpp"

// Constructor
Cat::Cat() {
    brain = new Brain();
    try {
        if (!brain)
            throw "Brain allocation failed!";
    } catch (const char* e) {
        std::cerr << e << std::endl;
    }
    std::cout << "Cat constructor called" << std::endl;
}

// Destructor
Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other) {  // Call the base class copy constructor
    brain = new Brain(*other.brain);  // Deep copy the brain
    std::cout << "Cat copy constructor called" << std::endl;
}

// Assignation operator
Cat& Cat::operator=(const Cat& other) {
    if (this != &other) { // Check for self-assignment
        Animal::operator=(other); // Call the base class assignation
        Brain* newBrain = new Brain(*other.brain); // Deep copy the brain
        try {
            if (!newBrain)
                throw "Brain allocation failed!";
        } catch (const char* e) {
            std::cerr << e << std::endl;
        }
        delete brain; // Delete the old brain
        brain = newBrain; // Assign the new brain
        std::cout << "Cat assignation operator called" << std::endl;
    }
    return *this; // Return the object
}

// Make sound
void Cat::makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
}

void Cat::modifyBrainIdea(int index, std::string idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getBrainIdea(int index) const {
    return brain->getIdea(index);
}
