#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon) {
    this->_name = name;
}

HumanA::~HumanA() {
}

void    HumanA::attack() const {
    if (this->_weapon.getType().empty())
        std::cout << this->_name << " attacks with his unconscious body of consciousness" << std::endl;
    else
        std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;

}
