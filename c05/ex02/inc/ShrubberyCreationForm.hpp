#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
	private:
		std::string	_target;
	protected:

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		virtual void	execute(Bureaucrat const &executor) const override;
};
