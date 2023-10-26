#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){
}

Zombie::~Zombie(void){
	std::cout << "Zombie named " << _name << " destroyed" << std::endl;
}

void Zombie::announce() const{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){
	_name = name;
	std::cout << _name << " is born!" << std::endl;
}