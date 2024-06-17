

#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"
#include "wrongCat.hpp"

int main()
{
	//--------- pdf main
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;


	//-------------------------
	std::cout << "\n---------------\n\n";

	{
		Animal	test;
		Cat		test2;
		Dog		test3;
		test.makeSound();
		test2.makeSound();
		test3.makeSound();
	}

	//--------- pdf wrong main
	std::cout << "\n---------------\n\n";

	const wrongAnimal* wrongmeta = new wrongAnimal();
	const wrongAnimal* wrongi = new wrongCat();
	std::cout << wrongi->getType() << " " << std::endl;
	wrongi->makeSound(); //will output the wronganimal sound!
	wrongmeta->makeSound();

	delete wrongmeta;
	delete wrongi;


	return 0;
}
