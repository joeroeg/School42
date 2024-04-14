#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
        club.setType("");
        bob.attack();
    }
    {
        HumanB jim("Jim");
        jim.attack();
        Weapon club = Weapon("crude spiked club");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
        club.setType("");
        jim.setWeapon(club);
        jim.attack();
    }
    return 0;
}
