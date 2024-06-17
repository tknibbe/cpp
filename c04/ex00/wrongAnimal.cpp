#include "wrongAnimal.hpp"
#include <iostream>

wrongAnimal::wrongAnimal(void){
	std::cout << "Default wrongAnimal constructor called" << std::endl;
	_type = "Some wrong Animal";
}

wrongAnimal::wrongAnimal(std::string type) : _type(type){
	std::cout << "wrongAnimal constructor called" << std::endl;
}

wrongAnimal::~wrongAnimal(void){
	std::cout << "wrongAnimal destructor called" << std::endl;
}

wrongAnimal::wrongAnimal(const wrongAnimal& ref){
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

wrongAnimal& wrongAnimal::operator=(const wrongAnimal& ref){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		this->_type = ref._type;
	}
	return *this;
}

void	wrongAnimal::makeSound() const{
	std::cout << "* WRONG ANIMAL SOUND *\n";
}

std::string wrongAnimal::getType() const {
	return _type;
}
