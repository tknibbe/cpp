

#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"
#include "wrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	j->makeSound();
	i->makeSound();
	delete j;//should not create a leak
	delete i;

	Animal *arr[100];

	for(int i=0;i<100;i++)
	{
		if (i%2)
			arr[i] = new Dog;
		else
			arr[i] = new Cat;
	}

	std::cout << "\n\n-------FINISHED ALLOCATION-----------\n\n\n";

	for(int i=0;i<100;i++){
		delete arr[i];
	}


	//-- deep copy examples
	Dog test;
	test.setIdea(0, "i should make these deep copies\n");

	Dog test2 = test;
	test2.setIdea(0, "if test's idea doesnt change this is a deep copy\n");


	std::cout << "test: " << test.getIdea(0) << std::endl;
	std::cout << "test2: " << test2.getIdea(0) << std::endl;
	test.setIdea(0, "new text\n");
	std::cout << "test: " << test.getIdea(0) << std::endl;
	std::cout << "test2: " << test2.getIdea(0) << std::endl;
	return 0;
}
