#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap& ref);
		ScavTrap&	operator=(const ScavTrap& ref);
		void	attack(const std::string& target);
		void	guardGate();
};