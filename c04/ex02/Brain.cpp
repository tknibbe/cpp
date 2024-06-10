#include "Brain.hpp"
#include <iostream>

Brain::Brain(void){
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain(void){
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& ref){
	std::cout << "Brain copy constructor called" << std::endl;
	*this = ref;
}

Brain& Brain::operator=(const Brain& ref){
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		for (int i=0;i<brainNumIdeas;i++)
			this->_ideas[i] = ref._ideas[i];
	}
	return *this;
}

void	Brain::setIdea(int index, std::string idea){
	if (index >= brainNumIdeas)
	{
		std::cout << "dont mess around like that man\n";
		exit(1);
	}
	_ideas[index] = idea;
}

std::string	Brain::getIdea(int index){
	if (index >= brainNumIdeas)
	{
		std::cout << "dont mess around like that man\n";
		exit(1);
	}
	return _ideas[index];
}
