#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private:
    FragTrap(); // default constructor to prevent creation of FragTrap without a name

public:
    FragTrap(std::string name); // parameterized constructor
    ~FragTrap(); // destructor
    FragTrap(const FragTrap &src); // copy constructor
    FragTrap &operator=(const FragTrap &rhs); // assignation operator

    void    highFivesGuys(void);
    void    displayStatus() const;
};

#endif
