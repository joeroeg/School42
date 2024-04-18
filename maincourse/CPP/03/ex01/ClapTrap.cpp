#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << "[ClapTrap] " << "constructor called for " << _name << std::endl;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "[ClapTrap] " << "destructor called for " << _name << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &src) {
    *this = src;
}

// Assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
    if (this != &rhs) {
        _name = rhs._name;
        _hit_points = rhs._hit_points;
        _energy_points = rhs._energy_points;
        _attack_damage = rhs._attack_damage;
    }
    return *this;
}

// Getters
void ClapTrap::attack(std::string const &target) {
    if (target.empty()) {
        std::cout << "No target to attack!" << std::endl;
        return;
    }
    if (_hit_points == 0) {
        std::cout << _name << " is dead!" << std::endl;
        return;
    }
    else if (_energy_points == 0) {
        std::cout << _name << " is out of energy to attack!" << std::endl;
        return;
    }
    else
    {
        std::cout << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
        _energy_points--;
    }
}

// Setters
void ClapTrap::takeDamage(unsigned int amount) {
    if (amount == 0) {
        std::cout << "No damage taken!" << std::endl;
        return;
    }
    if (_hit_points > 0) {
        if (_hit_points > amount) {
            std::cout << "[ClapTrap] " << _name << " takes " << amount << " points of damage!" << std::endl;
            _hit_points -= amount;
        } else {
            std::cout << "[ClapTrap] " << _name << " takes " << _hit_points << " points of damage and is now dead!" << std::endl;
            _hit_points = 0;
        }
    } else {
        std::cout << _name << " is already dead!" << std::endl;
    }
}

// Setters
void ClapTrap::beRepaired(unsigned int amount) {
    if (_hit_points == 0) {
        std::cout << "Repair failed. Clappy is dead!" << std::endl;
        return;
    }
    if (_energy_points > 0) {
        if (amount == 0) {
            std::cout << "No repair done!" << std::endl;
            return;
        }
        std::cout << "[ClapTrap] " << this->_name << " is repaired his hit points by " << amount << " points! Total hit points: " << _hit_points << std::endl;
        _energy_points--;
    } else {
        std::cout << "Not enough energy to repair. Current energy: " << _energy_points << std::endl;
    }
}

void ClapTrap::displayStatus() const {
    std::cout << "\033[25;2m";
    std::cout << "\nName: " << _name << std::endl;
    std::cout << "Hit Points: " << _hit_points << std::endl;
    std::cout << "Energy Points: " << _energy_points << std::endl;
    std::cout << "Attack Damage: " << _attack_damage << std::endl;
    std::cout << "\033[0m\n";
}

