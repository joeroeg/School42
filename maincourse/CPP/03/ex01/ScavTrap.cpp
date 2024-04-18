#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    // ClapTrap(name) is called first.
    // After ClapTrap's constructor completes, ScavTrap's constructor initializes its additional members.
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    // std::cout << this->_name << " is Constructed!" << std::endl;
    std::cout << "\033[25;2m[ScavTrap] \033[0m" << "constructor called for " << this->_name << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    // std::cout << "ScavTrap copy constructor called." << std::endl;
    std::cout << "\033[25;2m[ScavTrap] \033[0m" << "copy constructor called for " << other._name << std::endl;
}

// Assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);  // Assign base class parts
        this->_hit_points = other._hit_points;
        this->_energy_points = other._energy_points;
        this->_attack_damage = other._attack_damage;
        std::cout << "[ScavTrap] " << "assignment operator called for " << other._name << std::endl;
    }
    return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
    // std::cout << this->_name << " is Destructed!" << std::endl;
    std::cout << "\033[25;2m[ScavTrap] \033[0m" << "destructor called for " << this->_name << std::endl;
}

// Member functions
void ScavTrap::attack(std::string const &target) {
    if (target.empty()) {
        std::cout << "No target to attack!" << std::endl;
        return;
    }
    if (this->_hit_points == 0) {
        std::cout << this->_name << " is dead!" << std::endl;
        return;
    }
    else if (this->_energy_points == 0) {
        std::cout << this->_name << " is out of energy to attack!" << std::endl;
        return;
    }
    else
    {
        // std::cout << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
        std::cout << "\033[25;2m[ScavTrap] \033[0m" << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_points--;
    }
}

// Member functions
void ScavTrap::guardGate() {
    std::cout << "\033[25;2m[ScavTrap] \033[0m" << this->_name << " has entered in Gate keeper mode!" << std::endl;
}
