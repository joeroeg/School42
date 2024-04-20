#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain *brain;

public:
    Cat(); // Default constructor
    Cat(const Cat &copy); // Copy constructor
    Cat &operator=(const Cat &copy); // Assignation operator
    virtual ~Cat(); // Destructor

    virtual void makeSound() const;
    void modifyBrainIdea(int index, std::string idea);
    std::string getBrainIdea(int index) const;
};

#endif
