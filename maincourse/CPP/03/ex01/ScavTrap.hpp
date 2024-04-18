#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
    ScavTrap();

public:

    ScavTrap(std::string name); // constructor
    ~ScavTrap(); // destructor
    ScavTrap(const ScavTrap &src); // copy constructor
    ScavTrap &operator=(const ScavTrap &rhs); // assignation operator

    void    attack(std::string const& target);
    void    guardGate();
};

#endif
