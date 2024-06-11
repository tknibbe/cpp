#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type) : _type(type){
	// std::cout << "AMateria default constructor called" << std::endl;
	// globalFloor->addNode(this);
}

AMateria::~AMateria(void){
	// std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& ref){
	// std::cout << "AMateria copy constructor called" << std::endl;
	*this = ref;
}

AMateria& AMateria::operator=(const AMateria& ref){
	// std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		this->_type = ref._type;
	}
	return *this;
}

std::string const & AMateria::getType() const{
	return _type;
}

//is this supposed to be in this class?
void AMateria::use(ICharacter& target) {
	std::cout << "replace this function\n";
	std::cout << "using AMateria on " << target.getName() << "\n";
}