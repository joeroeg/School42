#include "ClapTrap.hpp"
#include <iostream>

int main() {
    // Create a ClapTrap
    ClapTrap ct("Clappy");

	// Show initial state
	std::cout << "ClapTrap initial state:" << std::endl;
	ct.displayStatus();

    std::cout << "\nTesting Normal Operations:" << std::endl;
    ct.attack("Target1");
    ct.takeDamage(3);
    ct.beRepaired(2);

    // Show the state after normal operations
    std::cout << "ClapTrap after normal operations:" << std::endl;
    ct.displayStatus();

    std::cout << "\nTesting Boundary Conditions:" << std::endl;
    // Assuming ClapTrap starts with 10 energy points and 10 hit points

    // Try attacking until energy is depleted
    for (int i = 0; i < 10; i++) {
        ct.attack("Target2");
    }
    // Try one more attack with zero energy
    ct.attack("Target2");

    // Reset for further tests
    ct.beRepaired(10); // Assume this also replenishes energy for simplicity

    // Take damage until hit points are depleted
    ct.takeDamage(5);
    ct.takeDamage(5);
    // Try taking more damage when at 0 hit points
    ct.takeDamage(1);

    // Try repairing when at full health and zero energy
    ct.beRepaired(1);

    // Show final state
    std::cout << "\nClapTrap after boundary and failure tests:" << std::endl;
    ct.displayStatus();

    return 0;
}
