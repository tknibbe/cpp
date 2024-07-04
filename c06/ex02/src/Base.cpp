#include "../inc/Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base::~Base(void){
	std::cout << "Base destructor called" << std::endl;
}

Base*	Base::generate(void){
	static	bool timeBeenSet;
	if (!timeBeenSet)
	{
		std::srand(std::time(nullptr));
		timeBeenSet = true;
	}
	int	num = rand() % 3;

	switch (num)
	{
	case 0:
		std::cout << "creating a new A class!\n";
		return (new A());
	case 1:
		std::cout << "creating a new B class!\n";
		return (new B());
	case 2:
		std::cout << "creating a new C class!\n";
		return (new C());
	}
	return nullptr;
}
void	Base::identify(Base* p){
	std::cout << "Identify() with a pointer\n";

	if (dynamic_cast<A*> (p) != NULL)
		std::cout << "Its a A class!\n";
	else if (dynamic_cast<B*> (p) != NULL)
		std::cout << "Its a B class!\n";
	else if (dynamic_cast<C*> (p) != NULL)
		std::cout << "Its a C class!\n";
	else
		std::cout << "Unknown Class\n";
}

void	Base::identify(Base& p){
	std::cout << "Identify() with a reference\n";

	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "It's a A class!\n";
	}
	catch (std::bad_cast& e){
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "It's a B class!\n";
		}
		catch (std::bad_cast& e){
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "It's a C class!\n";
			}
			catch (std::bad_cast& e){
				std::cout << "Unknown class\n";
			}
		}
	}
}