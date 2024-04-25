#include "Character.hpp"


Character::Character(std::string const &name) : _name(name) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

std::string const& Character::getName() const {
    return _name;
}

Character::~Character() {
}


void Character::printInventory(const Character& name) {
    for (int i = 0; i < 4; ++i) {
        if (name._inventory[i] != nullptr)
            std::cout << "Slot " << i << ": " << name._inventory[i]->getType() << std::endl;
        else
            std::cout << "Slot " << i << ": Empty" << std::endl;
    }
}


void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i] == nullptr) {
            _inventory[i] = m;
            break;
        }
    }
}


void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        _inventory[idx] = nullptr;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
}
