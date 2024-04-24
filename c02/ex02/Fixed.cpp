#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(){
	// std::cout << "Default constructor called\n";
	_Value = 0;
}

Fixed::Fixed(const int num){
	// std::cout << "Int constructor called\n";
	_Value = num << _Bits;
}

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

bool	Fixed::operator>(const Fixed& ref) const {
	return (this->_Value > ref._Value);
}

bool	Fixed::operator<(const Fixed& ref) const {
	return (this->_Value < ref._Value);
}

bool	Fixed::operator<=(const Fixed& ref) const {
	return (this->_Value <= ref._Value);
}

bool	Fixed::operator>=(const Fixed& ref) const {
	return (this->_Value >= ref._Value);
}

bool	Fixed::operator==(const Fixed& ref) const {
	return (this->_Value == ref._Value);
}

bool	Fixed::operator!=(const Fixed& ref) const {
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

Fixed	Fixed::operator/(const	Fixed& ref){
	float	num = static_cast<float> (this->_Value) / static_cast<float>(ref._Value);
	Fixed	temp(num);

	return temp;
}

Fixed&	Fixed::operator++() {
	_Value++;
	return *this;
}

Fixed	Fixed::operator++(int num) {
	(void) num;
	Fixed	temp(*this);
	_Value++;
	return (temp);
}

Fixed&	Fixed::operator--() {
	_Value--;
	return *this;
}

Fixed	Fixed::operator--(int num) {
	(void) num;
	Fixed	temp(*this);
	_Value--;
	return (temp);
}

Fixed&	Fixed::min(Fixed& left, Fixed& right){
	return (left < right ? left : right);
}

const Fixed&	Fixed::min(const Fixed& left, const Fixed& right){
	return (left < right ? left : right);
}

Fixed&	Fixed::max(Fixed& left, Fixed& right){
	return (left > right ? left : right);
}

const Fixed&	Fixed::max(const Fixed& left, const Fixed& right){
	return (left > right ? left : right);
}
