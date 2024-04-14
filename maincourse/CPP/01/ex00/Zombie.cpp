#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
    std::cout << name << ": is being created" << std::endl;
}
Zombie::~Zombie() {
    std::cout << name << ": is being destroyed" << std::endl;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
