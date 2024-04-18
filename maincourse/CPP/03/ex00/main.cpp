#include "ClapTrap.hpp"

int main() {
	ClapTrap claptrap("Claptrap");

	claptrap.attack("some target");
	claptrap.takeDamage(100);
	claptrap.beRepaired(3);

	return 0;
}
