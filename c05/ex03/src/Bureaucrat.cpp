#include "../inc/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("DefaultGuy"), _grade(150){
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name){
	std::cout << "Bureaucrat default constructor called" << std::endl;
	this->setGrade(grade);
}

Bureaucrat::~Bureaucrat(void){
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : _name(ref._name), _grade(ref._grade){
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref){
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		_grade = ref._grade;
	}
	return *this;
}

void	Bureaucrat::setGrade(int grade){
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

int Bureaucrat::getGrade(void) const{
	return (_grade);
}

const std::string &Bureaucrat::getName() const{
	return (_name);
}


void	Bureaucrat::incrementGrade(){
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade(){
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(AForm &form){
	try{
		form.beSigned(*this);
	}
	catch(const std::exception& e){
		std::cout << _name << " couldn't sign " << form.getName() << " because: " << e.what() <<"\n";
		return ;
	}
	std::cout << _name << " signed " << form.getName() << "\n";
}

void	Bureaucrat::executeForm(AForm const &form){
	try{
		form.execute(*this);
	}
	catch (const std::exception& e){
		std::cout << _name << " couldn't execute " << form.getName() << " because: " << e.what() << "\n";
		return;
	}
	std::cout << _name << " executed " << form.getName() << "\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade too low. can only assign from 1-150\n");
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade too high. can only assign from 1-150\n");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat& b){
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << "\n";
	return (out);
}