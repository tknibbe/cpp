
#pragma once

#include <string>

class	ClapTrap{
	private:
		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(ClapTrap& ref);
		ClapTrap&	operator=(ClapTrap& ref);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
