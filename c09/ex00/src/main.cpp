#include "../inc/BitcoinExchange.hpp"

int main(int argc, char**argv)
{
	if (argc != 2)
	{
		std::cerr << "please supply the input file\n";
		return(1);
	}

	BitcoinExchange	bit;

	std::string filename = argv[1];

	bit.getUserInput(filename);
	
}