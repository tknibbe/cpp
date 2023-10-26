#include <iostream>

int main(void){

	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout	<< "address of the string	: " << &str << std::endl
				<< "address of stringPTR	: " << stringPTR << std::endl
				<< "address of stringREF	: " << &stringREF << std::endl << std::endl;
	std::cout	<< "value of the string	: " << str << std::endl
				<< "value of stringPTR	: " << *stringPTR << std::endl
				<< "value of stringREF	: " << stringREF << std::endl;
	return EXIT_SUCCESS;
}