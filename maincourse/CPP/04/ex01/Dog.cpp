#include "Dog.hpp"

// Constructor
Dog::Dog() {
    brain = new Brain();
    try {
        if (!brain)
            throw "Brain allocation failed!";
    } catch (const char* e) {
        std::cerr << e << std::endl;
    }
    std::cout << "Dog constructor called" << std::endl;
}

// Destructor
Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);
    try {
        if (!brain)
            throw "Brain allocation failed!";
    } catch (const char* e) {
        std::cerr << e << std::endl;
    }
    std::cout << "Dog copy constructor called" << std::endl;
}


// Assignation operator
Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        Brain* newBrain = new Brain(*other.brain);
        try {
            if (!newBrain)
                throw "Brain allocation failed!";
        } catch (const char* e) {
            std::cerr << e << std::endl;
        }
        delete brain;
        brain = newBrain;
        std::cout << "Dog assignation operator called" << std::endl;
    }
    return *this;
}

// // Copy constructor (shallow copy)  Implementing shallow copy in the copy constructor and assignment operator
// Dog::Dog(const Dog& other) : Animal(other) {
//     brain = other.brain;  // Shallow copy: copy the pointer only
//     std::cout << "Dog copy constructor called" << std::endl;
// }

// // Assignation operator (shallow copy)
// Dog& Dog::operator=(const Dog& other) {
//     if (this != &other) {
//         Animal::operator=(other);
//         delete brain;  // Remove the old Brain object if any
//         brain = other.brain;  // Shallow copy: copy the pointer only
//     }
//     return *this;
// }

// Make sound
void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}

void Dog::modifyBrainIdea(int index, std::string idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getBrainIdea(int index) const {
    return brain->getIdea(index);
}

std::string Dog::getBrainAddress() const {
    return brain->getAddress();
}
