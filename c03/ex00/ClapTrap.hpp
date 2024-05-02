
#pragma once

#include <string>

class	ClapTrap{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		unsigned int	_maxHP;

	public:
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(ClapTrap& ref);
		ClapTrap&	operator=(ClapTrap& ref);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
