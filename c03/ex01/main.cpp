#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main(void)
{
	// ClapTrap trappie("trappie");
	// ClapTrap clap("clappie");

	// trappie.attack("enemy");
	// trappie.takeDamage(9);
	// trappie.takeDamage(9);
	// trappie.takeDamage(9);
	// trappie.attack("enemy");
	// trappie.beRepaired(10000);
	// clap.attack("anotherenemy");
	// clap.beRepaired(1);

	// ClapTrap defo;
	// ScavTrap def;

	ScavTrap scav("Scavie");
	scav.takeDamage(50);
	scav.beRepaired(999999);
	scav.attack("enemyguy");
	scav.guardGate();
	scav.takeDamage(9999);
	scav.guardGate();
	scav.attack("another enemy");
	scav.beRepaired(999999);
}