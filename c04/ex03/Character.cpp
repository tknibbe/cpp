#include "Character.hpp"
#include <iostream>

Character::Character(std::string name) : _name(name){
	for (int i=0;i<4;i++)
		_inventory[i] = nullptr;
	std::cout << "Character constructor called" << std::endl;
}

Character::Character() : _name("DefaultName"){
	for (int i=0;i<4;i++)
		_inventory[i] = nullptr;
	std::cout << "Character default constructor called" << std::endl;
}

Character::~Character(void){
	for (int i=0;i<4;i++)
		delete _inventory[i];
	std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character& ref) : _name(ref._name) {
	std::cout << "Character copy constructor called" << std::endl;
	for (int i=0;i<4;i++)
	{
		if (ref._inventory[i] != nullptr)
			this->_inventory[i] = ref._inventory[i]->clone();
		else
			this->_inventory[i] = nullptr;
	}
}

Character& Character::operator=(const Character& ref){
	// std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		this->_name = ref._name;

		for (int i=0;i<4 && this->_inventory[i] != nullptr;i++) // delete materia "this" has any
		{
			delete this->_inventory[i];
			this->_inventory[i] = nullptr;
		}

		for (int i=0;i<4 && ref._inventory[i] != nullptr;i++) // copy new instances of materia into "this"
			this->_inventory[i] = ref._inventory[i]->clone();
	}
	return *this;
}

std::string const &	Character::getName(void) const {
	return _name;
}

void	Character::equip(AMateria *m){
	if (m == nullptr)
	{
		std::cout << "no materia given to equip\n";
		return ;
	}

	int idx;
	for (idx = 0;idx < 4;idx++) //find first empty slot
		if (_inventory[idx] == nullptr)
			break;

	if (idx == 4)	//if inventory is full
	{
		std::cout << "inventory is full. dropping materia on the floor\n";
		globalFloor->addNode(m->clone());
		return;
	}

	globalFloor->deleteNode(m);
	std::cout << "equipping " << m->getType() << " into slot " << idx << "\n";
	_inventory[idx] = m->clone();
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
	while (idx < 3)
	{
		if (_inventory[idx] == nullptr)
			break;
		_inventory[idx] = _inventory[idx + 1];
		idx++;
	}
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