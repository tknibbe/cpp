#pragma once

#include "Animal.hpp"

class Dog : public Animal {
	private:

	protected:

	public:
		Dog();
		~Dog();
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		void	makeSound(void) const override;
};
