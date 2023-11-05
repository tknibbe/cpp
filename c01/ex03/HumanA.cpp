#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon){
	std::cout << "HumanA " << _name << " is made. with [" << _weapon.getType() << "] as a weapon" << std::endl;
}

HumanA::~HumanA(void){
	std::cout << "HumanA " << _name << " is destroyed" << std::endl;
}

void	HumanA::attack(void){
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}