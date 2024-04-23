#include "Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
    std::cout << "Character " << _name << " created" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(Character const &src)
{
    std::cout << "Character " << _name << " created" << std::endl;
    *this = src;
}

Character &Character::operator=(Character const &src)
{
    _name = src._name;
    std::cout << "Character " << _name << " created" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
        _inventory[i] = src._inventory[i]->clone();
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character " << _name << " destroyed" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

std::string const &Character::getName() const
{
    // std::cout << "Character getName() method called" << std::endl;
    return _name;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    std::cout << "Character equip() method called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        // printf("inventory[%d]: %p\n", i, _inventory[i]);
        if (!_inventory[i])
        {
            _inventory[i] = m;
            // printf("inventory[%d]: %p\n", i, _inventory[i]);
            return;
        }
    }
}

void Character::unequip(int idx)
{
    std::cout << "Character unequip() method called" << std::endl;
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return;
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    // std::cout << "Character use() method called" << std::endl;
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return;
    _inventory[idx]->use(target);
}
