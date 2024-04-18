#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << _name << " is Constructed!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << _name << " is Destructed!" << std::endl;
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
    if (_hit_points == 0) {
        std::cout << _name << " is dead!" << std::endl;
        return;
    }
    else if (_energy_points == 0) {
        std::cout << _name << " is out of energy!" << std::endl;
        return;
    }
    else
    {
        std::cout << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
        _energy_points--;
    }
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
    if (_energy_points > 0 && _hit_points > 0) {
        _hit_points += amount;
        std::cout << "Clappy is repaired for " << amount << " points!" << std::endl;
        _energy_points--;
    } else if (_hit_points <= 0) {
        std::cout << "Repair failed. Clappy is dead!" << std::endl;
    } else {
        std::cout << "Not enough energy to repair." << std::endl;
    }
}


void ClapTrap::displayStatus() const {
    std::cout << "Name: " << _name << std::endl;
    std::cout << "Hit Points: " << _hit_points << std::endl;
    std::cout << "Energy Points: " << _energy_points << std::endl;
    std::cout << "Attack Damage: " << _attack_damage << std::endl;
}
