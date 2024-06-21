#include <iostream>
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main(void){
	Bureaucrat	Larry("Larry", 3);
	Bureaucrat	Barry("Barry", 120);

	ShrubberyCreationForm	shrub("Home");

	std::cout << "\n-----signing and executing shrub form with Larry----\n";
	try{
		Larry.signForm(shrub);
	}
	catch(std::exception &e){
		std::cout << "exception caught! " << e.what() << "\n";
	}
	try {
		shrub.execute(Larry);
	}
	catch(std::exception &e){
		std::cout << "exception caught! " << e.what() << "\n";
	}
	std::cout << "trying to execute with Barry\n";
	try {
		shrub.execute(Barry);
	}
	catch(std::exception &e){
		std::cout << "exception caught! " << e.what() << "\n";
	}
	

	RobotomyRequestForm	robo("Jan");
	std::cout << "\n---trying to execute unsigned robo form----\n";
	try{
		robo.execute(Larry);
	}
	catch(std::exception &e){
		std::cout << "exception caught! " << e.what() << "\n";
	}


	std::cout << "\n----signing Robo form---\n";
		try{
		Larry.signForm(robo);
	}
	catch(std::exception &e){
		std::cout << "exception caught! " << e.what() << "\n";
	}
	std::cout << "\n-----executing robo form in loop----\n\n";
	for (int i =0;i<5;i++)
	{
		try {
			robo.execute(Larry);
		}
		catch(std::exception &e){
			std::cout << "exception caught! " << e.what() << "\n";
		}
	}

	std::cout << "---presidential pardon---\n";
	PresidentialPardonForm	pres("Jan");
	Larry.signForm(pres);
	try {
		pres.execute(Larry);
	}
	catch(std::exception &e){
		std::cout << "exception caught! " << e.what() << "\n";
	}

	std::cout << "\n-----testing new Bureaucrat::executeForm function-----\n";

	Barry.executeForm(pres);
	Barry.executeForm(shrub);

	Larry.executeForm(pres);
	Larry.executeForm(robo);
}