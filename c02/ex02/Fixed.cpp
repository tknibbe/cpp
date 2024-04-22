#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(){
	// std::cout << "Default constructor called\n";
	_Value = 0;
}

//converts int to corresponding fixed point value
Fixed::Fixed(const int num){
	// std::cout << "Int constructor called\n";
	_Value = num << _Bits;
}

//converts float to fixed point value
Fixed::Fixed(const float num){
	// std::cout << "Float constructor called\n";
	_Value = roundf(num * (1 << _Bits));
}

Fixed::~Fixed(){
	// std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& ref){
	// std::cout << "Copy construtor called\n";
	_Value = ref._Value;
}

void	Fixed::setRawBits(int const raw){
	// std::cout << "setRawBits member function called\n";
	_Value = raw;
}

int		Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called\n";
	return _Value;
}

float	Fixed::toFloat() const{
	return static_cast<float>(_Value) / (1 << _Bits);
}

int	Fixed::toInt() const{
	return _Value >> _Bits;
}

Fixed&	Fixed::operator=(const Fixed& ref){
	// std::cout << "Copy assignment operator called\n";
	if (this != &ref)
		_Value = ref._Value;
	return *this;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& ref){
	os << ref.toFloat();
	return os;
}

bool	Fixed::operator>(const Fixed& ref){
	return (this->_Value > ref._Value);
}

bool	Fixed::operator<(const Fixed& ref){
	return (this->_Value < ref._Value);
}

bool	Fixed::operator<=(const Fixed& ref){
	return (this->_Value <= ref._Value);
}

bool	Fixed::operator>=(const Fixed& ref){
	return (this->_Value >= ref._Value);
}

bool	Fixed::operator==(const Fixed& ref){
	return (this->_Value == ref._Value);
}

bool	Fixed::operator!=(const Fixed& ref){
	return (this->_Value != ref._Value);
}

Fixed	Fixed::operator+(const	Fixed& ref){
	Fixed	temp;

	temp._Value = this->_Value + ref._Value;
	return temp;
}

Fixed	Fixed::operator-(const	Fixed& ref){
	Fixed	temp;

	temp._Value = this->_Value - ref._Value;
	return temp;
}

Fixed	Fixed::operator*(const	Fixed& ref){

	Fixed	temp;
	long int	value = this->_Value * ref._Value;
	
	temp._Value = value >> _Bits;
	return temp;
}

// do i need to do the same thing here as *?
Fixed	Fixed::operator/(const	Fixed& ref){
	Fixed	temp(this->toFloat() / ref.toFloat());

	return temp;
}

Fixed&	Fixed::operator++() {
	_Value++;
	return *this;
}

float	Fixed::operator++(int num) {
	(void) num;
	float	temp = this->toFloat();
	_Value++;
	return (temp);
}

Fixed&	Fixed::operator--() {
	_Value--;
	return *this;
}

float	Fixed::operator--(int num) {
	(void) num;
	float	temp = this->toFloat();
	_Value--;
	return (temp);
}