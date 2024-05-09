#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : 
		ClapTrap("Default_name_clap_name",
				FragTrap::_baseHP,
				ScavTrap::_baseEP,
				FragTrap::_baseATK,
				FragTrap::_baseHP),
		_name("Default_name") {
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : 
		ClapTrap(name + "_clap_name",
				FragTrap::_baseHP,
				ScavTrap::_baseEP,
				FragTrap::_baseATK,
				FragTrap::_baseHP),
		_name(name) {
	std::cout << "DiamondTrap constructor called" << std::endl;
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

void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void){
	std::cout << _name << " is my name! " << ClapTrap::_name << " is my claptrap name!\n";
	//display BOTH names (read pdf you nerd)
}
