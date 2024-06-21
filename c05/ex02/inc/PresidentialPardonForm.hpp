#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string	_target;
	protected:

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
		virtual void	execute(Bureaucrat const &executor) const override;

};
