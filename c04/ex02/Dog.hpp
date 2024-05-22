#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *_brain;
	protected:

	public:
		Dog();
		~Dog();
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		void	makeSound(void) const override;
		void	setIdea(int index, std::string idea);
		std::string	getIdea(int index);
};
