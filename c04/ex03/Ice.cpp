#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice"){
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice(void){
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice& ref) : AMateria("ice"){
	std::cout << "Ice copy constructor called" << std::endl;
	*this = ref;
}

Ice& Ice::operator=(const Ice& ref){
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		this->_type = ref._type;
	}
	return *this;
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice* Ice::clone() const{
	return new Ice(*this);
}