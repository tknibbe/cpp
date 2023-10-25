#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	_name = name;
	announce();
}

Zombie::~Zombie(void){
	std::cout << "Zombie " << _name << " is dead" << std::endl;
}

void Zombie::announce() const{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}