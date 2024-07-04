#include "../inc/Data.hpp"
#include <iostream>

Data::Data(int value, std::string name) : _value(value), _name(name){
	std::cout << "Data default constructor called" << std::endl;
}

Data::~Data(void){
	std::cout << "Data destructor called" << std::endl;
}

Data::Data(const Data& ref){
	std::cout << "Data copy constructor called" << std::endl;
	*this = ref;
}

Data& Data::operator=(const Data& ref){
	std::cout << "Data copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		_value = ref._value;
		_name = ref._name;
	}
	return *this;
}

int	Data::getValue(){
	return (_value);
}

std::string Data::getName(){
	return (_name);
}