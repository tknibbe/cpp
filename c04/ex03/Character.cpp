#include "Character.hpp"
#include <iostream>

Character::Character(std::string name) : _name(name){
	for (int i=0;i<4;i++)
		_inventory[i] = nullptr;
	std::cout << "Character default constructor called" << std::endl;
}

Character::~Character(void){
	for (int i=0;i<4;i++)
		delete _inventory[i];
	std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character& ref){
	std::cout << "Character copy constructor called" << std::endl;
	*this = ref;
}
//TODO : make deep copy
Character& Character::operator=(const Character& ref){
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		this->_name = ref._name;
		// this->_inventory = ref._inventory;  TODO
	}
	return *this;
}

std::string const &	Character::getName(void) const {
	return _name;
}

void	Character::equip(AMateria *m){
	int idx = 0;
	while (idx < 4) //find first empty slot
	{
		if (_inventory[idx] == nullptr)
			break;
		idx++;
	}

	if (idx == 4)	//if inventory is full
	{
		std::cout << "inventory is full. dropping materia on the floor\n";
		return;
	}

	globalFloor->deleteNode(m);
	std::cout << "equipping " << m->getType() << " into slot " << idx << "\n";
	_inventory[idx] = m;
}
void	Character::unequip(int idx){
	if (idx < 0 || idx > 3)
	{
		std::cout << "inventory is from index 0-3\n";
		return ;
	}
	if (_inventory[idx] == nullptr)
	{
		std::cout << "there is nothing to unequip\n";
		return ;
	}

	std::cout << "unequipping " << _inventory[idx]->getType() << " from slot " << idx << "\n";
	globalFloor->addNode(_inventory[idx]);
	_inventory[idx] = nullptr;
}

void	Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3)
	{
		std::cout << "Cannot use that id. inventory goes from 0-3\n";
		return ;
	}
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "nothing equiped in that slot\n";
}