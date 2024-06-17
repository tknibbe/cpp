

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
	delete j; //should not create a leak
	delete i;

	// making and deleting array of animals
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
	std::cout << "\n\n-------FINISHED DELETION-----------\n\n\n";


	//-- deep copy examples
	Dog test;
	test.setIdea(0, "i should make these deep copies\n");

	Dog test2 = test;
	test2.setIdea(0, "if test's idea doesnt change this is a deep copy\n");


	std::cout << "\ntest: " << test.getIdea(0) << std::endl;
	std::cout << "test2: " << test2.getIdea(0) << std::endl;
	std::cout << "test: " << test.getIdea(0) << std::endl;

	test.setIdea(0, "new text\n");
	std::cout << "changed test's idea to 'new text'. test2's idea should remain unchanged\n\n";
	std::cout << "test: " << test.getIdea(0) << std::endl;
	std::cout << "test2: " << test2.getIdea(0) << std::endl;

	//----- reassigned leak test
	Dog	leak;	//allocates new brain on the heap
	leak.setIdea(0, "leaks?");
	Dog newguy;
	leak = newguy;	//could overwrite the "leak" class and forget the allocated brain


	return 0;
}
