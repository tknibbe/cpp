#pragma once

#include <string>

class wrongAnimal {
	private:

	protected:
		std::string _type;
	public:
		wrongAnimal();
		wrongAnimal(std::string type);
		virtual ~wrongAnimal();
		wrongAnimal(const wrongAnimal& other);
		wrongAnimal&	operator=(const wrongAnimal& other);
		std::string getType() const;
		void	makeSound() const;
};
