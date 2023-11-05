#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name){
	_name = name;
	_weapon = NULL;
	std::cout << "HumanA " << _name << " is made. with no weapon" << std::endl;
}

HumanB::~HumanB(void){
	std::cout << "HumanA " << _name << " is destroyed" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon){
	_weapon = &weapon;
	std::cout << _name << " has now equipped a weapon [" << _weapon->getType() << "]" << std::endl;
}

void	HumanB::attack(void){
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their tiny little unarmed fists" << std::endl;

}