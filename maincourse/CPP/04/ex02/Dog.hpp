#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain *brain;

public:
    Dog(); // Default constructor
    Dog(const Dog &copy); // Copy constructor
    Dog &operator=(const Dog &copy); // Assignation operator
    virtual ~Dog(); // Destructor

    virtual void makeSound() const;
    void modifyBrainIdea(int index, std::string idea);
    std::string getBrainIdea(int index) const;
    std::string getBrainAddress() const;
};

#endif
