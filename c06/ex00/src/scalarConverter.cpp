#include "../inc/scalarConverter.hpp"
#include <iostream>

scalarConverter::scalarConverter(void){
	std::cout << "scalarConverter default constructor called" << std::endl;
	/*
		set default values
	*/
}

scalarConverter::~scalarConverter(void){
	std::cout << "scalarConverter destructor called" << std::endl;
}

scalarConverter::scalarConverter(const scalarConverter& ref){
	std::cout << "scalarConverter copy constructor called" << std::endl;
	*this = ref;
}

scalarConverter& scalarConverter::operator=(const scalarConverter& ref){
	std::cout << "scalarConverter copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		/*
		specify instructions here
		*/
	}
	return *this;
}
