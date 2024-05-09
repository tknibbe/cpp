#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void): FragTrap(), ScavTrap(){
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	_name = "Default_name";
	ClapTrap::_name	= "Default_name_clap_name";
	_hitPoints		= FragTrap::_hitPoints;
	_energyPoints	= ScavTrap::_energyPoints; // why does this still assign Frag ep?
	_attackDamage	= FragTrap::_attackDamage;
	std::cout	<<	"Diamondtrap stats:\nHP : " << _hitPoints
				<<	" (should be 100)\nEP : " << _energyPoints
				<<	" (should be 50)\nATK: " << _attackDamage << " (Should be 30)\n\n";
	//how to make attack() choose the ScavTrap one?
}

DiamondTrap::DiamondTrap(std::string name): FragTrap(), ScavTrap(){
	std::cout << "DiamondTrap constructor called" << std::endl;
	_name = name;
}

DiamondTrap::~DiamondTrap(void){
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& ref){
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = ref;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& ref){
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		this->_hitPoints	=	ref._hitPoints;
		this->_energyPoints	=	ref._energyPoints;
		this->_attackDamage	=	ref._attackDamage;
		this->_maxHP		=	ref._maxHP;
	}
	return *this;
}

void	DiamondTrap::whoAmI(void){
	std::cout << _name << " is my name!\n";
	//display BOTH names (read pdf nerd)
}