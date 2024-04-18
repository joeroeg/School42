#include "ClapTrap.hpp"
#include <iostream>

/*
1. Hit Points
Purpose: Hit points represent the health of the ClapTrap.
Functionality: When the hit points reach 0, the ClapTrap can be considered "dead" or non-operational.

2. Energy Points
Purpose: Energy points are used to perform actions such as attacking or repairing.
Functionality: Each action typically consumes a set amount of energy points.
Once energy points are depleted, the ClapTrap cannot perform any more actions until they are replenished.

3. Attack Damage
Purpose: Attack Damage determines how much damage ClapTrap causes to the target when it attacks.
Functionality: Whenever the ClapTrap attacks another entity, the target's hit points are reduced by the amount of the ClapTrap's attack damage.
*/

int main() {
    // Create a ClapTrap
    ClapTrap ct("Clappy");

    std::cout << "Initial Status:";
    ct.displayStatus();

    std::cout << "\nTesting Edge Cases:" << std::endl;
    ct.takeDamage(0);  // No damage should not alter hit points
    ct.beRepaired(0);  // No repair should not alter hit points
    ct.attack("");     // Attack with empty string target
    ct.attack("VeryVeryLongTargetNameThatExceedsNormalUsageVeryVeryLongTargetNameThatExceedsNormalUsageVeryVeryLongTargetNameThatExceedsNormalUsageVeryVeryLongTargetNameThatExceedsNormalUsageVeryVeryLongTargetNameThatExceedsNormalUsageVeryVeryLongTargetNameThatExceedsNormalUsageVeryVeryLongTargetNameThatExceedsNormalUsage");  // Test with long string

    std::cout << "\nTesting Normal Operations:" << std::endl;
    ct.attack("Target1");
    ct.takeDamage(1);
    ct.beRepaired(1);
    ct.displayStatus();

    std::cout << "\nTesting Boundary Conditions:" << std::endl;
    for (int i = 1; i <= 3; i++) {
        ct.attack("Target2");  // This should deplete energy to zero
    }
    ct.attack("Target2");  // Attack with zero energy

    ct.beRepaired(15);  // Attempt to repair beyond maximum hit points

    std::cout << "Status after boundary tests:";
    ct.displayStatus();

    ct.takeDamage(12);  // Exceed hit points in damage
    ct.beRepaired(2);   // Try to repair when dead

    std::cout << "\nFinal Status:";
    ct.displayStatus();

    return 0;
}

