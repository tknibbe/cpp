#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
	private:

	protected:
		static int	_baseHP;
		static int	_baseEP;
		static int	_baseATK;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap& ref);
		ScavTrap&	operator=(const ScavTrap& ref);
		void	attack(const std::string& target);
		void	guardGate();
};