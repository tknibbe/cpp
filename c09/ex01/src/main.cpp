#include "../inc/RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {

	if (argc != 2)
	{
		std::cerr << "Incorrect amount of arguments\n";
		return (1);
	}
	
	RPN	calc;

	calc.calculate(argv[1]);
	return 0;
}