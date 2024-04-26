#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Ice : public AMateria {
public:
    Ice();
    Ice(std::string const& type);
    virtual ~Ice();
    Ice(Ice const& other);
    Ice& operator=(Ice const& src);

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif
