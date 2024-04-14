#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->_name = name;
    this->_weapon = NULL;
}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon &weapon) {
    this->_weapon = &weapon;
}

void HumanB::attack()
{
    if (this->_weapon == NULL)
    {
        std::cout << this->_name << " doesn't have a weapon to attack." << std::endl;
        return;
    }
    else if (this->_weapon->getType() == "")
    {
        std::cout << this->_name << " attacks with his unconscious body of consciousness" << std::endl;
        return;
    }
    else
        std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}
