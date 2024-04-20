#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>


/**
 * @brief The Animal class is an abstract class that represents an animal.
 * @details The Animal class is an abstract class that represents an animal. It has a type attribute and a pure virtual function makeSound.
 * @note The default destructor is virtual to ensure that the destructor of the derived class is called when deleting a pointer to the base class.
 * in other words, the destructor of the derived class is called when deleting a pointer to the base class. This is called polymorphic behavior.
**/
class Animal {
protected:
    std::string type; // Protected so derived classes can access and set it

public:
    Animal(); // Default constructor
    Animal(std::string type); // Parameterized constructor
    Animal(const Animal &copy); // Copy constructor
    Animal &operator=(const Animal &copy); // Assignation operator
    virtual ~Animal(); // Virtual destructor for proper cleanup in derived classes

    std::string getType() const;
    virtual void makeSound() const = 0; // Pure virtual function
};

#endif
