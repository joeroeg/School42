#include "Character.hpp"

// container for dropped Materia
std::vector<AMateria*> droppedMateria;

// Parametrized constructor
Character::Character(std::string const &name) : _name(name) {
    std::cout << "Character " << _name << " created" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

// Destructor
Character::~Character() {
    std::cout << "Character " << _name << " destroyed" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (_inventory[i])
            delete _inventory[i];
    }
}

std::string const &Character::getName() const {
    return _name;
}

// Copy Constructor (Deep copy)
Character::Character(const Character &src) : _name(src._name) {
    std::cout << "Creating copy of Character: " << _name << std::endl;
    for (int i = 0; i < 4; ++i)
        if (src._inventory[i])
        {
            _inventory[i] = src._inventory[i]->clone();
            std::cout << "Copying inventory slot " << i << ": " << _inventory[i] << std::endl;
        }
        else
        {
            _inventory[i] = NULL;
            std::cout << "Copying inventory slot " << i << ": " << _inventory[i] << std::endl;
        }
}

// Copy Assignment Operator (deep copy)
Character &Character::operator=(const Character &rhs) {
    if (this != &rhs) {
        _name = rhs._name;
        for (int i = 0; i < 4; ++i) {
            delete _inventory[i];
            if (rhs._inventory[i])
            {
                _inventory[i] = rhs._inventory[i]->clone();
                std::cout << "Assigning inventory slot " << i << ": " << _inventory[i] << std::endl;
            }
            else
                _inventory[i] = NULL;
        }
    }
    return *this;
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

void Character::printInventory(const Character& name) {
    for (int i = 0; i < 4; ++i) {
        if (name._inventory[i] != NULL)
            std::cout << "Slot " << i << ": " << name._inventory[i]->getType() << " " << name._inventory[i] <<std::endl;
            // std::cout << "Slot " << i << ": " << typeid(*_inventory[i]).name() << " at " << _inventory[i] << std::endl;
        else
            std::cout << "Slot " << i << ": Empty" << std::endl;
    }
}


void cleanupDroppedMateria() {
    for (std::vector<AMateria*>::iterator it = droppedMateria.begin(); it != droppedMateria.end(); ++it) {
        delete *it;
    }
    droppedMateria.clear();
}
