#include <iostream>
#include "ScavTrap.hpp"

// int main() {
//     // Create a ScavTrap instance
//     ScavTrap scav("Guardian");
//     scav.attack("intruder");
//     scav.takeDamage(10);
//     scav.beRepaired(5);
//     scav.guardGate();

//     std::cout << "\n--- Copy Constructor Test ---\n";
//     // Copy constructor test
//     ScavTrap scavCopy(scav);
//     scavCopy.attack("enemy");

//     std::cout << "\n--- Assignment Operator Test ---\n";
//     // Assignment operator test
//     ScavTrap scavAssigned = scav;
//     scavAssigned.attack("another intruder");

//     return 0;
// }

int main( void )
{
    ScavTrap ash( "Ash" );
    ScavTrap ash2( ash );

    // ash.attack( "the air" );
    // ash.takeDamage( 10 );
    // ash.beRepaired( 10 );
    // ash.guardGate();

    return EXIT_SUCCESS;
}
