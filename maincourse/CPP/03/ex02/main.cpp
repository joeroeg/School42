#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
    // Create a FragTrap instance
    ClapTrap clap1("Clap");
    ScavTrap scav1("Scav");
    FragTrap frag1("Frag");

    // Copy constructor test
    ClapTrap clap2(clap1);
    ScavTrap scav2(scav1);
    FragTrap frag2(frag1);

    // Display that attributes are initialized to the requested values.
    clap1.displayStatus();
    scav1.displayStatus();
    frag1.displayStatus();

    clap2.displayStatus();
    scav2.displayStatus();
    frag2.displayStatus();

    // Assignment operator test
    ClapTrap clap3 = clap1;
    ScavTrap scav3 = scav1;
    FragTrap frag3 = frag1;

    // Display that attributes are initialized to the requested values.
    clap3.displayStatus();
    scav3.displayStatus();
    frag3.displayStatus();

    // Attack
    clap1.attack("enemy");
    clap2.attack("enemy");
    scav1.attack("enemy");
    scav2.attack("enemy");
    frag1.attack("enemy");
    frag2.attack("enemy");

    // Take damage
    clap1.takeDamage(100);
    clap2.takeDamage(5);
    scav1.takeDamage(100);
    scav2.takeDamage(5);
    frag1.takeDamage(100);
    frag2.takeDamage(5);

    // Be repaired
    clap1.beRepaired(10);
    clap2.beRepaired(10);
    scav1.beRepaired(10);
    scav2.beRepaired(10);
    frag1.beRepaired(10);
    frag2.beRepaired(10);

    // Guard gate request - Unique functionality of ScavTrap
    scav1.guardGate();
    scav2.guardGate();

    // High fives request - Unique functionality of FragTrap
    frag1.highFivesGuys();
    frag2.highFivesGuys();

    return 0;
}

