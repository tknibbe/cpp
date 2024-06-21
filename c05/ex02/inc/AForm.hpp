#pragma once
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed = false;
		const int			_gradeToSign;
		const int			_gradeToExec;
	protected:

	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		~AForm();
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		void	checkGrades();
		void	beSigned(Bureaucrat &b);
		virtual void	execute(Bureaucrat const &executor) const = 0;


	//getters
		const std::string	&getName() const;
		bool				getSignedStatus() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;

	//exceptions
		class	GradeTooHighException : public std::exception{
			const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception{
			const char *what() const throw();
		};
		class	FormUnsigned : public std::exception{
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream& out, AForm &f);
