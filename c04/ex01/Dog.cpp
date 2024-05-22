#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog"){
	std::cout << "Dog Default constructor called" << std::endl;
	_brain = new Brain;
}

Dog::~Dog(void){
	delete _brain;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog& ref){
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = ref;
}

Dog& Dog::operator=(const Dog& ref){
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		this->_type = ref._type;
		this->_brain = new Brain(*ref._brain);
	}
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "* WOOF *\n";
}
void	Dog::setIdea(int index, std::string idea){
	_brain->setIdea(index, idea);
}

std::string	Dog::getIdea(int index){
	return _brain->getIdea(index);
}