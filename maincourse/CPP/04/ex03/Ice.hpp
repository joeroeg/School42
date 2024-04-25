#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice(); // default constructor
    Ice(std::string const& type); // parameterized constructor
    virtual ~Ice(); // destructor
    Ice(Ice const& src); // copy constructor
    Ice& operator=(Ice const& src); // assignment operator

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif
