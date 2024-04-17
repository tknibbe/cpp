#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void){
	std::cout << "Default constructor called\n";
	_Value = 0;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& ref){
	std::cout << "Copy constructor called\n";
	*this = ref;
	// this->_Value = ref._Value;
}

Fixed& Fixed::operator=(const Fixed& ref){
	std::cout << "Copy assignment operator called\n";
	if (this != &ref)
		this->_Value =  ref._Value;
	return *this;
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return this->_Value;
}

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called\n";
	this->_Value = raw;
}