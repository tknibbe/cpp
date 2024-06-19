#include <iostream>
#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main(void){
	
	std::cout << "\n-----Testing construction grade ranges-----\n\n";

	std::cout << "grade of 0 on sign\n";
	try {
		Form	f("testForm", 0, 49);
	}
	catch (const std::exception& e){
		std::cout << "exception caught! " << e.what() << "\n";
	}

	std::cout << "grade of 0 on exec\n";
	try {
		Form	f("testForm", 149, 0);
	}
	catch (const std::exception& e){
		std::cout << "exception caught! " << e.what() << "\n";
	}

	std::cout << "grade of 151 on sign\n";
	try {
		Form	f("testForm", 151, 14);
	}
	catch (const std::exception& e){
		std::cout << "exception caught! " << e.what() << "\n";
	}

	std::cout << "grade of 151 on exec\n";
	try {
		Form	f("testForm", 13, 151);
	}
	catch (const std::exception& e){
		std::cout << "exception caught! " << e.what() << "\n";
	}

	std::cout << "-----testing signing ranges-----\n\n";

	Bureaucrat	bob("Bob", 50);

	std::cout << "\nsigning a level 50 form w/a level 50 Bureaucrat\n";
	try {
		Form		sign("testForm", 50, 20);
		bob.signForm(sign);
	}
	catch (const std::exception& e){
		std::cout << "exception caught! " << e.what() << "\n";
	}

	std::cout << "\nsigning level 51 form w/a level 50 bureaucrat\n";
	try {
		Form	sign("testForm", 51, 20);
		bob.signForm(sign);
	}
	catch (const std::exception& e){
		std::cout << "exception caught! " << e.what() << "\n";
	}

	std::cout << "\nsigning level 49 form w/a level 50 bureaucrat\n";
	try {
		Form	sign("testForm", 49, 20);
		bob.signForm(sign);
	}
	catch (const std::exception& e){
		std::cout << "exception caught! " << e.what() << "\n";
	}

	//testing insertion overload and signed state
	Form	sign("testForm", 150, 20);
	std::cout << sign << "\n";
	bob.signForm(sign);
	std::cout << sign << "\n";
}