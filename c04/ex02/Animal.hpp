#pragma once

#include <string>

class Animal {
	private:

	protected:
		std::string _type;
	public:
		Animal();
		Animal(std::string name);
		virtual ~Animal();
		Animal(const Animal& other);
		Animal&	operator=(const Animal& other);
		std::string	getType() const;
		virtual void makeSound(void) const = 0; // this is now a pure virtual function
};