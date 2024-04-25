#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter {
private:
    std::string _name;
    AMateria* _inventory[4];

public:
    Character(std::string const& name);
    virtual ~Character();
    Character(const Character &src);
    Character& operator=(const Character &rhs);

    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
    void printInventory(const Character& name);
};

#endif
