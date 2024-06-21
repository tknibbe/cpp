#include "../inc/AForm.hpp"
#include <iostream>

AForm::AForm(void) :	_name("defaultAForm"),
					_gradeToSign(150),
					_gradeToExec(150){
	std::cout << "AForm default constructor called" << std::endl;
	this->checkGrades();
}

AForm::AForm(std::string name, int signGrade, int execGrade) :
			_name(name),
			_gradeToSign(signGrade),
			_gradeToExec(execGrade){
	std::cout << "AForm constructor called" << std::endl;
	this->checkGrades();
}
AForm::~AForm(void){
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm& ref) :
				_name(ref._name),
				_gradeToSign(ref._gradeToSign),
				_gradeToExec(ref._gradeToExec){
	std::cout << "AForm copy constructor called" << std::endl;
	this->checkGrades();
}

AForm& AForm::operator=(const AForm& ref){
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		_signed = ref._signed;
	this->checkGrades();
	}
	return *this;
}

const std::string &AForm::getName(void) const{
	return (_name);
}

bool	AForm::getSignedStatus(void) const{
	return (_signed);
}

int AForm::getGradeToSign(void) const{
	return (_gradeToSign);
}

int AForm::getGradeToExec(void) const{
	return (_gradeToExec);
}

void	AForm::checkGrades(void){
	if (_gradeToExec < 1 || _gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToExec > 150 || _gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

void	AForm::beSigned(Bureaucrat &b){
	if (b.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream& out, AForm &ref){
	out << "Form name: " << ref.getName()
		<< "\nsigned: " << std::boolalpha << ref.getSignedStatus()
		<< "\ngrade to sign: " << ref.getGradeToSign()
		<< "\ngrade to exec: " << ref.getGradeToExec() << "\n";
	return (out);
}

const char *AForm::GradeTooHighException::what() const throw(){
	return ("Grade too high\n");
}

const char *AForm::GradeTooLowException::what() const throw(){
	return ("Grade too low\n");
}

const char *AForm::FormUnsigned::what() const throw(){
	return ("Form is not signed\n");
}
