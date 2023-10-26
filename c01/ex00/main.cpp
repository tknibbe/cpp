#include "Zombie.hpp"

int main(void)
{
	//heap allocated class
	Zombie *zombie = newZombie("Jan");
	if (!zombie)
		return EXIT_FAILURE;
	delete zombie;

	//stack allocated class
	randomChump("Jan2");
	
	return EXIT_SUCCESS;
}