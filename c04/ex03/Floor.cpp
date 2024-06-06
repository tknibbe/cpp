#include "Floor.hpp"
#include <iostream>

Floor::Floor(const AMateria *m){
	_materia = m;
	_next = nullptr;
	std::cout << "Floor default constructor called" << std::endl;
}

Floor::~Floor(void){
	std::cout << "Floor destructor called" << std::endl;
}

Floor::Floor(const Floor& ref){
	std::cout << "Floor copy constructor called" << std::endl;
	*this = ref;
}

Floor& Floor::operator=(const Floor& ref){
	std::cout << "Floor copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		
	}
	return *this;
}

void	Floor::addNode(const AMateria* m){
	if (!globalFloor)
	{
		globalFloor = new Floor(m);
		std::cout << "Adding " << m->getType() << " to the floor\n";
		return ;
	}

	Floor *temp = globalFloor;
	while (temp->_next != nullptr)
		temp = temp->_next;
	temp->_next = new Floor(m);
	std::cout << "Adding " << m->getType() << " to the floor\n";
}

void	Floor::deleteNode(const AMateria* m){
	Floor	*first = globalFloor;
	Floor	*second;

	if (first->_next == nullptr) //empties list if only item is deleted
	{
		delete globalFloor;
		globalFloor = nullptr;
		return;
	}
	if (globalFloor->_materia == m) //moves globalFloor* if the first node is getting deleted
	{
		first = globalFloor;
		globalFloor = globalFloor->_next;
		delete first;
		return ;
	}


	while (first) //move first pointer until node m, second will be the node before
	{
		second = first;
		first = first->_next;
		if (!first || first->_materia == m)
			break;
	}
	if (!second)
	{
		std::cout << "Node to be deleted not found on the floor\n";
		return ;
	}
	if (first)
	{
		second->_next = first->_next; // set next to the one after m
		delete first;
		return ;
	}
	// std::cout << "Deleted " << m->getType() << " from the floor\n";
	globalFloor->print();
}

void	Floor::print(void){
	if(!globalFloor)
		std::cout << "Floor is empty\n";
	else
	{
		Floor *temp = globalFloor;
		std::cout << "the floor contains:\n";
		while (temp)
		{
			std::cout << "a " << temp->_materia->getType() << "\n";
			temp = temp->_next;
		}
	}
}

void	Floor::deleteWholeList(void){
	Floor *temp = globalFloor;
	Floor *temp2;

	while (temp)
	{
		std::cout << "deleting node " << "\n";
		temp2 = temp;
		temp = temp->_next;
		delete temp2->_materia;
		delete	temp2;
	}

}