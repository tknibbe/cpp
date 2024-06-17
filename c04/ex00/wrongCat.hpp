#pragma once
#include "wrongAnimal.hpp"

class wrongCat : public wrongAnimal {
	private:

	protected:

	public:
		wrongCat();
		~wrongCat();
		wrongCat(const wrongCat& other);
		wrongCat&	operator=(const wrongCat& other);
		void	makeSound() const;
};
