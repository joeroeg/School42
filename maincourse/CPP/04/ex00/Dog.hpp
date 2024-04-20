#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog(); // Default constructor
    Dog(const Dog &copy); // Copy constructor
    Dog &operator=(const Dog &copy); // Assignation operator
    virtual ~Dog(); // Destructor

    virtual void makeSound() const;
};

#endif
