#include "Animal.hpp"
#include <iostream>

Animal::Animal(void){
	std::cout << "Animal Default constructor called" << std::endl;
	_type = "Some Animal";
}
Animal::Animal(std::string type) : _type(type){
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal(void){
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal& ref){
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = ref;
}

Animal& Animal::operator=(const Animal& ref){
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		this->_type = ref._type;
	}
	return *this;
}

std::string Animal::getType() const {
	return _type;
}

void	Animal::makeSound() const {
	std::cout << "* UNIDENTIFIED ANIMAL SOUND *\n";
}