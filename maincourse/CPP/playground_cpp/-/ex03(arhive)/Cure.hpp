#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure(); // default constructor
    Cure(std::string const & type); // parameterized constructor
    virtual ~Cure(); // destructor
    Cure(Cure const & src); // copy constructor
    Cure & operator=(Cure const & src); // assignment operator

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif

