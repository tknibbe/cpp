#include <iostream>
#include "../inc/Bureaucrat.hpp"

int main(void){

	std::cout << "\n-----Testing grade ranges-----\n\n";


	std::cout << "Grade of 0:\n";
	try {
		Bureaucrat	Larry("Larry", 0);
	}
	catch (std::exception &ex){
		std::cout << "caught exception! " << ex.what() << "\n";
	}

	std::cout << "Grade of 151:\n";
	try {
		Bureaucrat	Larry("Larry", 151);
	}
	catch (std::exception &ex){
		std::cout << "caught exception! " << ex.what() << "\n";
	}

	std::cout << "Grade of 1:\n";
	try {
		Bureaucrat	Larry("Larry", 1);
	}
	catch (std::exception &ex){
		std::cout << "caught exception! " << ex.what() << "\n";
	}

	std::cout << "Grade of 150:\n";
	try {
		Bureaucrat	Larry("Larry", 150);
	}
	catch (std::exception &ex){
		std::cout << "caught exception! " << ex.what() << "\n";
	}
	

	std::cout << "\n-----Testing in/decrement-----\n\n";


	Bureaucrat Larry("Larry", 1);
	std::cout << "\ntrying to increment a grade 1\n";
	try {
		Larry.incrementGrade();
	}
	catch (std::exception& ex){
		std::cout << "caught exception! " << ex.what();
	}
	std::cout << Larry << "\n";

	std::cout << "trying to decrement a grade 150\n";
	Larry.setGrade(150);
	try {
		Larry.decrementGrade();
	}
	catch (std::exception& ex){
		std::cout << "caught exception! " << ex.what();
	}
	std::cout << Larry << "\n";

	std::cout << "incrementing a grade 150\n";
	try {
		Larry.incrementGrade();
	}
	catch (std::exception& ex){
		std::cout << "caught exception! " << ex.what();
	}
	std::cout << Larry << "\n";

	Larry.setGrade(1);
	std::cout << "decrementing a grade 1\n";
	try {
		Larry.decrementGrade();
	}
	catch (std::exception& ex){
		std::cout << "caught exception! " << ex.what();
	}
	std::cout << Larry << "\n";


	std::cout << "---testing assignment operator since the name is static---\n\n";
	Bureaucrat	Bob("Bob", 39);
	Larry = Bob;	//Larry will still be called Larry since the name of the object is const
	std::cout << Larry << "\n";
	std::cout << Bob << "\n";

	std::cout << "---testing copy assignment---\n\n";
	Bureaucrat	Henry(Larry); //will be called Larry since its a copy
	std::cout << Henry << "\n";

}