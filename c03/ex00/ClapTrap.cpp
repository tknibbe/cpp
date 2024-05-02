#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : _name(name){
	std::cout << "constructor called\n";
	_hitPoints 		= 10;
	_energyPoints	= 10;
	_attackDamage	= 0;
	_maxHP			= 10;
}

ClapTrap::~ClapTrap(){
	std::cout << "destructor called\n";
}

ClapTrap::ClapTrap(ClapTrap& ref){
	*this = ref;
}

ClapTrap&	ClapTrap::operator=(ClapTrap& ref){
	if (this != &ref)
	{
		_name = ref._name;
		_hitPoints = ref._hitPoints;
		_energyPoints = ref._energyPoints;
		_attackDamage = ref._attackDamage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target){
	if (_energyPoints == 0 || _hitPoints == 0)
	{
		std::cout << "Claptrap " << _name << " is dead or has no energy left. he cannot attack " << target << "\n";
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (_hitPoints == 0)
	{
		std::cout << "Claptrap " << _name << " is already dead! leave him alone :(\n";
		return ;
	}
	// set damage amount so HP cannot go below 0
	amount = amount > _hitPoints ? _hitPoints : amount;

	_hitPoints -= amount;
	std::cout << "Claptrap " << _name << " takes " << amount << " damage! what a blow! it now has " << _hitPoints << " HP left\n";
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (_energyPoints == 0 || _hitPoints == 0)
	{
		std::cout << "Claptrap " << _name << " is dead or has no energy left. it cannot be repaired\n";
		return;
	}
	//set repair amount so HP cannot go above _maxHP
	amount = _hitPoints + amount > _maxHP ? _maxHP - _hitPoints : amount;

	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " is repairing. gaining " << amount << " of HP (now at " << _hitPoints << ")\n";
	_energyPoints--;
}