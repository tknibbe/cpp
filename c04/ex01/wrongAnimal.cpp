#include "wrongAnimal.hpp"
#include <iostream>

wrongAnimal::wrongAnimal(void){
	std::cout << "Default constructor called" << std::endl;
	_type = "Some wrong Animal";
}

wrongAnimal::wrongAnimal(std::string type) : _type(type){
	std::cout << "Animal constructor called" << std::endl;
}

wrongAnimal::~wrongAnimal(void){
	std::cout << "Destructor called" << std::endl;
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

void	wrongAnimal::makeSound(){
	std::cout << "* WRONG ANIMAL SOUND *\n";
}