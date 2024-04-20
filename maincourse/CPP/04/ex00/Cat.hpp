#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat(); // Default constructor
    Cat(const Cat &copy); // Copy constructor
    Cat &operator=(const Cat &copy); // Assignation operator
    virtual ~Cat(); // Destructor

    virtual void makeSound() const;
};

#endif
