
#pragma once

#include <string>

class	ClapTrap{
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		unsigned int	_maxHP;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int atk, unsigned int maxhp);
		~ClapTrap();
		ClapTrap(ClapTrap& ref);
		ClapTrap&	operator=(ClapTrap& ref);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
