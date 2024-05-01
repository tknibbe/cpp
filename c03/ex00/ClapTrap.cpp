#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : _name(name){
	std::cout << "constructor called\n";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 10;
}

ClapTrap::~ClapTrap(){
	std::cout << "destructor called\n";
}

ClapTrap::ClapTrap(ClapTrap& ref){
	_name = ref._name;
	//do i also  copy hp, ep and atkdmg?
}

ClapTrap&	ClapTrap::operator=(ClapTrap& ref){
	if (this != &ref)
		this->_name = ref._name;
	//copy other data?
	return *this;
}

void	ClapTrap::attack(const std::string& target){
	if (_energyPoints == 0)
		return ;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (_hitPoints <= 0)
	{
		std::cout << "Claptrap " << _name << " is already dead! leave him alone :(\n";
		return ;
	}
	_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (_energyPoints == 0)
		return;
	std::cout << "ClapTrap " << _name << " is repairing. gaining " << amount << " of HP\n";
	_energyPoints--;
}