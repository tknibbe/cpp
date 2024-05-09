#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap(){
	std::cout << "FragTrap Default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_maxHP			= 100;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30, 100){
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