#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure"){
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure(void){
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure& ref) : AMateria("cure"){
	std::cout << "Cure copy constructor called" << std::endl;
	*this = ref;
}

Cure& Cure::operator=(const Cure& ref){
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		this->_type = ref._type;
	}
	return *this;
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

Cure* Cure::clone() const{
	return new Cure(*this);
}