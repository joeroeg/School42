#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << _name << " is born!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << _name << " is dead!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
    *this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
    if (this != &rhs) {
        _name = rhs._name;
        _hit_points = rhs._hit_points;
        _energy_points = rhs._energy_points;
        _attack_damage = rhs._attack_damage;
    }
    return *this;
}

void ClapTrap::attack(std::string const &target) {
    if (_attack_damage == 0) {
        std::cout << _name << " has no attack damage!" << std::endl;
        return;
    }
    else if (_energy_points == 0) {
        std::cout << _name << " has no energy points!" << std::endl;
        return;
    }
    else if (_hit_points == 0) {
        std::cout << _name << " is dead!" << std::endl;
        return;
    }
    std::cout << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
    _energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << _name << " takes " << amount << " points of damage!" << std::endl;
    if (_hit_points < amount) {
        std::cout << _name << " is dead!" << std::endl;
        _hit_points = 0;
        return;
    }
    _hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << _name << " is repaired for " << amount << " points!" << std::endl;
    _hit_points += amount;
}
