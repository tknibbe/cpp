#pragma once

#include "Animal.hpp"

class Cat : public Animal{
	private:

	protected:

	public:
		Cat();
		~Cat();
		Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
		void	makeSound(void) const override;
};
