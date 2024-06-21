#include "../inc/ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void): 
						AForm("Shrubbery Creation Form", 145, 137),
						_target("default"){
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
						AForm("Shrubbery Creation Form", 145, 137),
						_target(target){
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref){
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = ref;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref){
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		_target = ref._target;
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor){
	if (this->getSignedStatus() == false)
		throw AForm::FormUnsigned();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();


	std::ofstream	target_file(_target + "_shrubbery");
	target_file << "                    _\n"
"                  _(_)_                          wWWWw   _\n"
"      @@@@       (_)@(_)   vVVVv     _     @@@@  (___) _(_)_\n"
"     @@()@@ wWWWw  (_)|    (___)   _(_)_  @@()@@   Y  (_)@(_)\n"
"      @@@@  (___)     `|/    Y    (_)@(_)  @@@@   ||/   (_)|\n"
"       /      Y       ||    ||/    /(_)    ||      |/      |\n"
"    | |     | |/       | / | | /  ||/       |/    ||      ||/\n"
"    |||//   |||///  ||||//||||/// ||///  ||||//  |||//  ||||// \n"
"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	target_file.close();
}
