#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) : _type(type) {
	std::cout << "Weapon is created [" << _type << "]" << std::endl;
}


Weapon::~Weapon(void){
	std::cout << "Weapon [" << getType() << "] being destroyed" << std::endl;
}

std::string const &Weapon::getType(void){
	return (_type);
}

void	Weapon::setType(std::string weapon){
	std::cout << "Changing Weapon [" << _type << "] to [" << weapon << "]" << std::endl;
	_type = weapon;
}