#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat"){
	std::cout << "Cat Default constructor called" << std::endl;
	_brain = new Brain;
}

Cat::~Cat(void){
	delete _brain;
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
		this->_brain = new Brain(*ref._brain);
	}
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "* MIAUW *\n";
}

void	Cat::setIdea(int index, std::string idea){
	_brain->setIdea(index, idea);
}

std::string	Cat::getIdea(int index){
	return _brain->getIdea(index);
}