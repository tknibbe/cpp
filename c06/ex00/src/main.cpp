#include "../inc/scalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv){

	//try to instansiate class
	// scalarConverter	scalar; //can't because constructor is private
	if (argc != 2)
	{
		std::cout << "Please supply one (1) argument\n";
		return (EXIT_FAILURE);
	}

	std::cout << "\nInput: " << argv[1] << "\n\n";

	//test scalarConverter here
	std::string input(argv[1]);
	scalarConverter::convert(input);


}