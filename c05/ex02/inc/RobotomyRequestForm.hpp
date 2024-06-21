#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	private:
		std::string	_target;
	protected:

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
		virtual void	execute(Bureaucrat const &executor) override;

};
