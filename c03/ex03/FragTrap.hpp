#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
	private:

	protected:
		static int	_baseHP;
		static int	_baseEP;
		static int	_baseATK;

	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap& other);
		FragTrap&	operator=(const FragTrap& other);
		void	highFivesGuys(void);
};
