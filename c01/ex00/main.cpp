#include "Zombie.hpp"

int main(void)
{
	//heap allocated class
	Zombie *zombie = newZombie("Jan");
	delete zombie;

	//stack allocated class
	randomChump("Jan2");
	
	return 0;
}