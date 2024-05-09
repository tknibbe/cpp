#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
	private:

	protected:

	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap& other);
		FragTrap&	operator=(const FragTrap& other);
		void	highFivesGuys(void);
};
