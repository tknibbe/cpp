#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat"){
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::~Cat(void){
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat& ref){
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = ref;
}

Cat& Cat::operator=(const Cat& ref){
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		this->_type = ref._type;
	}
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "* MIAUW *\n";
}