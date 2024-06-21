#pragma once
#include <string>
#include <ostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		unsigned int		_grade;
	protected:

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		void	signForm(AForm &f);
		void	executeForm(AForm const & form);

		//setters
		void	setGrade(int grade);

		//getters
		int		getGrade(void) const;
		const std::string &getName(void) const;

		//in/decremtent
		void	incrementGrade(void);
		void	decrementGrade(void);

		//exceptions
		class GradeTooLowException : public std::exception{
			const char* what() const throw();
		};
		class GradeTooHighException : public std::exception{
			const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat& b);
