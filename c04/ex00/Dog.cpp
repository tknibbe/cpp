#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog"){
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::~Dog(void){
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog& ref){
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = ref;
}

Dog& Dog::operator=(const Dog& ref){
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &ref)
	if (this != &ref)
	{
		this->_type = ref._type;
	}
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "* WOOF *\n";
}