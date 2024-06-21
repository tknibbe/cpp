#include "../inc/RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy request form", 72, 45), _target("default"){
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy request form", 72, 45), _target(target){
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void){
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref){
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = ref;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref){
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		_target = ref._target;
	}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor){
	if (this->getSignedStatus() == false)
		throw AForm::FormUnsigned();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();

	static int	fiftyfifty;
	if (fiftyfifty == 10000)
		fiftyfifty = 0;

	std::cout << "****BBZZZZZZZZZZ BZZZZZ*****\n****BBZZZZZZZZZZ BZZZZZ*****\n";
	if (fiftyfifty % 2)
		std::cout << _target << " has been successfully robotomized!\n";
	else
		std::cout << "the robotomization has failed! leaving " << _target << " behind handicapped and useless\n";
	fiftyfifty++;
}
