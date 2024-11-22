#include "BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange(void){
	std::cout << "Default constructor called" << std::endl;
	/*
		set default values
	*/
}

BitcoinExchange::~BitcoinExchange(void){
	std::cout << "Destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref){
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		/*
		specify instructions here
		*/
	}
	return *this;
}
