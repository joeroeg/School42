#include <iostream>
#include "FragTrap.hpp"

int main( void )
{
    // Create a FragTrap instance
    ClapTrap clap1("Clap");
    FragTrap frag1("Frag");

    // Copy constructor test
    ClapTrap clap2(clap1);
    FragTrap frag2(frag1);

    // Display that attributes are initialized to the requested values.
    clap1.displayStatus();
    frag1.displayStatus();
    clap2.displayStatus();
    frag2.displayStatus();

    // Assignment operator test
    ClapTrap clap3 = clap1;
    FragTrap frag3 = frag1;

    // Display that attributes are initialized to the requested values.
    clap3.displayStatus();
    frag3.displayStatus();

    // Attack
    clap1.attack("enemy");
    clap2.attack("enemy");
    frag1.attack("enemy");
    frag2.attack("enemy");

    // Take damage
    clap1.takeDamage(100);
    clap2.takeDamage(5);
    frag1.takeDamage(100);
    frag2.takeDamage(5);

    // Be repaired
    clap1.beRepaired(10);
    clap2.beRepaired(10);
    frag1.beRepaired(10);
    frag2.beRepaired(10);

    // High fives request - Unique functionality of FragTrap
    frag1.highFivesGuys();
    frag2.highFivesGuys();

    return 0;
}

