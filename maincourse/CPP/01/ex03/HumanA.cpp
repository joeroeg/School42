#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
}

HumanA::~HumanA() {
}

void    HumanA::attack() const {
    if (this->_weapon.getType().empty())
        std::cout << this->_name << " attacks with his unconscious body of consciousness" << std::endl;
    else
        std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;

}
