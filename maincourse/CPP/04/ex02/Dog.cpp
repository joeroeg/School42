#include "Dog.hpp"

// Constructor
Dog::Dog() {
    brain = new Brain(); // Create a new Brain object
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
/**
 * @brief Best practice for implementing the copy constructor
 * 1. Call the Base Class Copy Constructor: This is essential to ensure that all base class properties are correctly initialized. If your class inherits from another, always start by calling the base class's copy constructor using an initializer list.
 * 2. Perform Deep Copies of All Data Members: If your class manages resources like dynamic memory, or contains objects that do, you need to perform a deep copy of these resources to prevent issues like double deletion, memory leaks, and dangling pointers.
 * 3. Use Initializer Lists When Possible: For initializing members that are objects of other classes, using initializer lists ensures that these objects are constructed correctly before the body of the constructor executes.
*/
Dog::Dog(const Dog& other) : Animal(other) { // Call the base class copy constructor
    brain = new Brain(*other.brain); // Deep copy: copy the object
    try {
        if (!brain)
            throw "Brain allocation failed!";
    } catch (const char* e) {
        std::cerr << e << std::endl;
    }
    std::cout << "Dog copy constructor called" << std::endl;
}

/**
 * @brief Best practice for implementing the assignation operator
 * 1. Check for self-assignment (Handling of Self-Assignment: Crucial for avoiding issues such as unintended resource deallocation.)
 * 2. Call the base class assignation operator
 * 3. Perform the deep copy
 * 4. Delete the old resource
 * 5. Assign the new resource
 * 6. Return the object
 * @note Why do we need to return the object?
 * The assignation operator should return a reference to the object itself. This is because the assignation operator is expected to return a reference to the object that was assigned. This is a common practice in C++ and is known as method chaining.
 * This allows us to chain multiple assignments together.
*/
// // Assignation operator
Dog& Dog::operator=(const Dog& other) {
    if (this != &other) { // Check for self-assignment
        Animal::operator=(other); // Call the base class assignation
        Brain* newBrain = new Brain(*other.brain); // Deep copy: copy the object
        try { // Check if the allocation was successful
            if (!newBrain)
                throw "Brain allocation failed!";
        } catch (const char* e) { // Catch the exception
            std::cerr << e << std::endl;
        }
        delete brain; // Delete the old Brain object
        brain = newBrain; // Assign the new Brain object
        std::cout << "Dog assignation operator called" << std::endl;
    }
    return *this; // Return the object
}

// Copy constructor (shallow copy)  Implementing shallow copy in the copy constructor and assignment operator
// Dog::Dog(const Dog& other) : Animal(other) {
//     brain = other.brain;  // Shallow copy: copy the pointer only
//     std::cout << "Dog copy constructor called" << std::endl;
// }

// Assignation operator (shallow copy)
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
