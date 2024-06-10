

#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"
#include "wrongCat.hpp"

int main()
{
	// const Animal* meta = new Animal(); // is now an abstract class so wont compile
	// delete meta;
	// meta->makeSound(); // isn't possible because it Animal doesnt have a functoin definition for it

	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	delete i;
	delete j;
	return 0;
}
