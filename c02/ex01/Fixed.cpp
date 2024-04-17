#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(){
	std::cout << "Default constructor called\n";
	_Value = 0;
}

//converts int to corresponding fixed point value
Fixed::Fixed(const int num){
	std::cout << "Int constructor called\n";
	//code here
}

//converts float to fixed point value
Fixed::Fixed(const float num){
	std::cout << "Float constructor called\n";
	//convert here
	int	a = num * (1 << _Bits); //hopelijk is dit correct
	// std::cout << "a = " << a << '\n';
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& ref){
	std::cout << "Copy construtor called\n";
	//make it copy
}

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called\n";
	this->_Value = raw;
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return this->_Value;
}

float	Fixed::toFloat() const{
	std::cout << "Tofloat member function called\n";
	//code here
}

int	Fixed::toInt() const{
	std::cout << "toInt member function called\n";
	//code here
}

Fixed&	Fixed::operator=(const Fixed& ref){
	std::cout << "Copy assignment operator called\n";
	if (this != &ref)
		this->_Value = ref._Value;
}

void	Fixed::operator<<(const Fixed& ref){
	std::cout << "insertion operator called\n";
	//code here
}