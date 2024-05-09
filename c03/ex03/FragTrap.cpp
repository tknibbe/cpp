#include "FragTrap.hpp"
#include <iostream>

int FragTrap::_baseHP = 100;
int FragTrap::_baseEP = 100;
int FragTrap::_baseATK = 30;

FragTrap::FragTrap(void) : 
	ClapTrap("default_name", FragTrap::_baseHP, 
			FragTrap::_baseEP, FragTrap::_baseATK, FragTrap::_baseHP) {
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, FragTrap::_baseHP, 
			FragTrap::_baseEP, FragTrap::_baseATK, FragTrap::_baseHP){
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::~FragTrap(void){
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref){
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = ref;
}

FragTrap& FragTrap::operator=(const FragTrap& ref){
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		this->_hitPoints	=	ref._hitPoints;
		this->_energyPoints	=	ref._energyPoints;
		this->_attackDamage	=	ref._attackDamage;
		this->_maxHP		=	ref._maxHP;
	}
	return *this;
}

void	FragTrap::highFivesGuys(void){
	std::cout << "WOOOHHH, well done guys! give me some highfives!\n";
}