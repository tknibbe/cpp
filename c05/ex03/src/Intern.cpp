#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void){
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern(void){
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern& ref){
	std::cout << "Intern copy constructor called" << std::endl;
	*this = ref;
}

Intern& Intern::operator=(const Intern& ref){
	std::cout << "Intern copy assignment operator called" << std::endl;
	if (this != &ref)
	{}
	return *this;
}

AForm *Intern::makeForm(std::string formName, std::string targetName){
	
	const int numForms = 3;
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	int idx;
	for (idx =0; idx < numForms;idx++)
	{
		if (forms[idx] == formName)
			break;
	}

	if (idx < 3)
		std::cout << "intern creates " << forms[idx] << " form\n";
	switch (idx){
		case 0:
			return (new PresidentialPardonForm(targetName));
		case 1:
			return (new RobotomyRequestForm(targetName));
		case 2:
			return (new ShrubberyCreationForm(targetName));
		default:
			throw Intern::unknownFormRequest();
	}
}

const char *Intern::unknownFormRequest::what() const throw(){
	return ("An unknown form was requested");
}