#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap trappie("trappie");
	ClapTrap clap("clappie");

	trappie.attack("enemy");
	trappie.takeDamage(9);
	trappie.takeDamage(9);
	trappie.takeDamage(9);
	trappie.attack("enemy");
	trappie.beRepaired(10000);
	clap.attack("anotherenemy");
	clap.beRepaired(1);
}