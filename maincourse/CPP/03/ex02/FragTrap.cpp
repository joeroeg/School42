#include "FragTrap.hpp"

// Constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "\033[31;2m[FragTrap] \033[0m" << "constructor called for " << this->_name << std::endl;
}

// Destructor
FragTrap::~FragTrap() {
    std::cout << "\033[31;2m[FragTrap] \033[0m" << "destructor called for " << this->_name << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
    std::cout << "\033[31;2m[FragTrap] \033[0m" << "copy constructor called for " << this->_name << std::endl;
}

// Assignment operator
FragTrap &FragTrap::operator=(const FragTrap &rhs) {
    if (this != &rhs) {
        this->_name = rhs._name;
        this->_hit_points = rhs._hit_points;
        this->_energy_points = rhs._energy_points;
        this->_attack_damage = rhs._attack_damage;
    }
    std::cout << "\033[31;2m[FragTrap] \033[0m" << "assignment operator called for " << this->_name << std::endl;
    return *this;
}

// High fives request
void FragTrap::highFivesGuys(void) {
    std::cout << "\033[31;2m[FragTrap] \033[0m" << this->_name << " requests a high five!" << std::endl;
}

// Display status
void FragTrap::displayStatus() const {
    std::cout << "\033[31;2m[FragTrap] \033[0m" << "Status: " << this->_name << " has " << this->_hit_points << " hit points, " << this->_energy_points << " energy points, and " << this->_attack_damage << " attack damage." << std::endl;
}
