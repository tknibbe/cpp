#include "../inc/Base.hpp"
#include <iostream>

int main(void){

	std::cout << "Testing identification through pointers:\n\n";
	for (int i=0;i<5;i++)
	{
		Base	*p = Base::generate();
		Base::identify(p);
		delete	p;
		std::cout << "\n\n";
	}

	std::cout << "Testing identification through references:\n\n";
	for (int i=0;i<5;i++)
	{
		Base	*p = Base::generate();
		Base::identify(*p);
		delete	p;
		std::cout << "\n\n";
	}

	std::cout << "Testing identification with bullshit:\n\n";
	Base	*p = nullptr;
	Base::identify(p);
	Base::identify(*p);
}