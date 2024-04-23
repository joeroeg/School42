#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria *_inventory[4];

public:
    Character(); // default constructor
    Character(std::string const &name); // parameterized constructor
    Character(Character const &src); // copy constructor
    Character &operator=(Character const &src); // assignment operator
    virtual ~Character(); // destructor

    virtual std::string const &getName() const;
    virtual void equip(AMateria *m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter &target);
};

#endif
