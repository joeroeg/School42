#include "Character.hpp"

// container for dropped Materia
std::vector<AMateria*> droppedMateria;

Character::Character(std::string const &name) : _name(name) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

/**
 * @note If the destructor or unequip did not properly delete cloned objects,
 * they remained in memory without any references after the Character instance was destroyed or the inventory was altered, leading to leaks.
 * @note The Character destructor's role is to clean up all resources the object owns when it is destroyed.
 * By ensuring that the destructor deletes all AMateria objects in the inventory, you prevent AMateria objects from lingering in memory after the Character is gone.
*/
Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i])
            delete _inventory[i];
    }
}

std::string const& Character::getName() const {
    return _name;
}

// Copy Constructor (Deep copy)
/**
 * @note each Character instance has its own copies of AMateria objects, preventing interference between different Character instances.
*/
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
    if (!m)
        return;
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i] == NULL) {
            _inventory[i] = m->clone();
            std::cout << "Equipping materia at slot " << i << ": " << m << std::endl;
            return;
        }
    }
    std::cout << "Inventory full. Cannot equip new materia." << std::endl;
    // delete m;
}



void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
         droppedMateria.push_back(_inventory[idx]); // Move the unequipped Materia to the global container
        _inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
}

/**
 * @param std::vector<AMateria*>::iterator it - An iterator in C++ is similar to a pointer but specifically designed for working with STL containers like std::vector
 *
*/
void cleanupDroppedMateria() {
    for (std::vector<AMateria*>::iterator it = droppedMateria.begin(); it != droppedMateria.end(); ++it) {
        delete *it;
    }
    droppedMateria.clear();
}

