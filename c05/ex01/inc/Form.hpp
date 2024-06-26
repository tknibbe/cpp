#pragma once
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed = false;
		const int			_gradeToSign;
		const int			_gradeToExec;
	protected:

	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		~Form();
		Form(const Form& other);
		Form&	operator=(const Form& other);
		void	checkGrades();
		void	beSigned(Bureaucrat &b);

	//getters
		const std::string	&getName();
		bool				getSignedStatus();
		int					getGradeToSign();
		int					getGradeToExec();

	//exceptions
		class	GradeTooHighException : public std::exception{
			const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception{
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream& out, Form &f);
