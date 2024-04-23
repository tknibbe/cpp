
#pragma once

#include <string>

class	ClapTrap{
	private:
		std::string _name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;

	public:
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(ClapTrap& ref);
		ClapTrap&	operator=(ClapTrap& ref);
		
};
