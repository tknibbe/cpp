#include "../inc/Form.hpp"
#include <iostream>

Form::Form(void) :	_name("defaultForm"),
					_gradeToSign(150),
					_gradeToExec(150){
	std::cout << "Form default constructor called" << std::endl;
	this->checkGrades();
}

Form::Form(std::string name, int signGrade, int execGrade) :
			_name(name),
			_gradeToSign(signGrade),
			_gradeToExec(execGrade){
	std::cout << "Form constructor called" << std::endl;
	this->checkGrades();
}
Form::~Form(void){
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form& ref) :
				_name(ref._name),
				_gradeToSign(ref._gradeToSign),
				_gradeToExec(ref._gradeToExec){
	std::cout << "Form copy constructor called" << std::endl;
	this->checkGrades();
}

Form& Form::operator=(const Form& ref){
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		_signed = ref._signed;
	this->checkGrades();
	}
	return *this;
}

const std::string &Form::getName(void){
	return (_name);
}

bool	Form::getSignedStatus(void){
	return (_signed);
}

int Form::getGradeToSign(void){
	return (_gradeToSign);
}

int Form::getGradeToExec(void){
	return (_gradeToExec);
}

void	Form::checkGrades(void){
	if (_gradeToExec < 1 || _gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (_gradeToExec > 150 || _gradeToSign > 150)
		throw Form::GradeTooLowException();
}

void	Form::beSigned(Bureaucrat &b){
	if (b.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream& out, Form &ref){
	out << "Form name: " << ref.getName()
		<< "\nsigned: " << std::boolalpha << ref.getSignedStatus()
		<< "\ngrade to sign: " << ref.getGradeToSign()
		<< "\ngrade to exec: " << ref.getGradeToExec() << "\n";
	return (out);
}

const char *Form::GradeTooHighException::what() const throw(){
	return ("Grade too high\n");
}

const char *Form::GradeTooLowException::what() const throw(){
	return ("Grade too low\n");
}
