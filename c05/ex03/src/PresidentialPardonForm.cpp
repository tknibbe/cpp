#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential pardon form", 25, 5), _target("default"){
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential pardon form", 25, 5), _target(target){
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void){
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref){
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = ref;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref){
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		_target = ref._target;
	}
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const{
	if (this->getSignedStatus() == false)
		throw AForm::FormUnsigned();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();

	std::cout << "***We are happy to announce that " << _target << " has received a Presidential pardon from Zaphod Beeblebrox!\n";
}
