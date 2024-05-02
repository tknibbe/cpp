#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("defaultName", 100, 50, 20, 100){
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20, 100){
	std::cout << "ScavTrap constructor called\n";
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& ref){
	std::cout << "copy constructor called\n";
	*this = ref;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& ref){
	if (this != &ref)
	{
		this->_hitPoints	=	ref._hitPoints;
		this->_energyPoints	=	ref._energyPoints;
		this->_attackDamage	=	ref._attackDamage;
		this->_maxHP		=	ref._maxHP;
	}
	return *this;
}

void	ScavTrap::attack(const std::string& target){
	if (_energyPoints == 0 || _hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is dead or has no energy left. he cannot attack " << target << "\n";
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
	_energyPoints--;
}

void	ScavTrap::guardGate(){
	if (_hitPoints > 0 && _energyPoints > 0)
		std::cout << "ScavTrap " << _name << " is now in gate keeper mode\n";
	else
		std::cout << "ScavTrap " << _name << " is dead or tired and will not guard anything!\n";
}