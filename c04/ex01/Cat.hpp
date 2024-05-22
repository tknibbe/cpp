#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	private:
		Brain *_brain;
	protected:

	public:
		Cat();
		~Cat();
		Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
		void	makeSound(void) const override;
		void	setIdea(int index, std::string idea);
		std::string	getIdea(int index);
};
