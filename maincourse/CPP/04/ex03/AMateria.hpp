#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria {
protected:
    std::string _type;

public:
    AMateria(const std::string& type);
    virtual ~AMateria();
    AMateria(AMateria const& other);
    AMateria& operator=(const AMateria& src);

    std::string const& getType() const; // Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
