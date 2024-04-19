#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
    ScavTrap(); // default constructor to prevent creation of ScavTrap without a name

public:
    ScavTrap(std::string name); // parameterized constructor
    ~ScavTrap(); // destructor
    ScavTrap(const ScavTrap &src); // copy constructor
    ScavTrap &operator=(const ScavTrap &rhs); // assignation operator

    void    attack(std::string const& target);
    void    guardGate();
    void    displayStatus() const;
};

#endif
