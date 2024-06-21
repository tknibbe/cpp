#pragma once
#include "AForm.hpp"

class Intern {
	private:

	protected:

	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		AForm *makeForm(std::string formName, std::string targetName);

		class unknownFormRequest : public std::exception{
			const char *what() const throw();
		};
};
