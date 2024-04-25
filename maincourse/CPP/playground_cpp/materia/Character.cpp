#include "Character.hpp"


Character::Character(std::string const &name) : _name(name) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

std::string const& Character::getName() const {
    return _name;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        delete _inventory[i];  // Free each materia in the inventory
        _inventory[i] = nullptr;
    }
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

// Copy Constructor (shallow copy)
// Character::Character(const Character &src) : _name(src._name) {
//     std::cout << "Creating copy of Character: " << _name << std::endl;
//     for (int i = 0; i < 4; ++i) {
//         _inventory[i] = src._inventory[i];
//         std::cout << "Copying inventory slot " << i << ": " << _inventory[i] << std::endl;
//     }
// }

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

// Copy Assignment Operator (shallow copy)
// Character &Character::operator=(const Character &rhs) {
//     if (this != &rhs) {  // Protect against self-assignment
//         _name = rhs._name;
//         for (int i = 0; i < 4; ++i) {
//             delete _inventory[i]; // need to be deleted to prevent memory leaks
//             _inventory[i] = rhs._inventory[i]; // this copies only the pointer because _inventory is an array of pointers to object.
//         }
//     }
//     return *this;
// }

void Character::printInventory(const Character& name) {
    for (int i = 0; i < 4; ++i) {
        if (name._inventory[i] != NULL)
            std::cout << "Slot " << i << ": " << name._inventory[i]->getType() << " " << name._inventory[i] <<std::endl;
            // std::cout << "Slot " << i << ": " << typeid(*_inventory[i]).name() << " at " << _inventory[i] << std::endl;
        else
            std::cout << "Slot " << i << ": Empty" << std::endl;
    }
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i] == NULL) {
            _inventory[i] = m->clone();
            std::cout << "Equipping materia at slot " << i << ": " << m << std::endl;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        _inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
}
