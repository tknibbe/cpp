#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
	//-------------PROVIDED TEST-----
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl << std::endl;
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << std::endl << std::endl;

	//---------------OWN TEST---------------
	Weapon	ch("Charizard");
	Weapon	bl("Blastoise");
	HumanA	Ash("Ash", ch);
	HumanB	Brock("Brock");
	Ash.attack();
	Brock.attack();
	Brock.setWeapon(bl);
	Brock.attack();
	return 0;
}