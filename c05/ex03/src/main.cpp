#include <iostream>
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main(void){
	Intern someRandomIntern;
	AForm* rrf;
	try {
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}
	catch (std::exception &e){
		std::cout << "Exception caught! " << e.what() << "\n";
		return EXIT_FAILURE;
	}
	delete rrf;
	return EXIT_SUCCESS;
}