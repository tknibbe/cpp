#include "wrongCat.hpp"
#include "wrongAnimal.hpp"
#include <iostream>

wrongCat::wrongCat(void) : wrongAnimal("wrongCat"){
	std::cout << "Default wrongCat constructor called" << std::endl;
}

wrongCat::~wrongCat(void){
	std::cout << "wrongCat destructor called" << std::endl;
}

wrongCat::wrongCat(const wrongCat& ref){
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

wrongCat& wrongCat::operator=(const wrongCat& ref){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		this->_type =  ref._type;
	}
	return *this;
}

void	wrongCat::makeSound() const{
	std::cout << "* WRONG CAT SOUND\n";
}