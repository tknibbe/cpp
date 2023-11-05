#include <string>
#include "Weapon.hpp"

#pragma once

class HumanB {
	private:
		std::string	_name;
		Weapon		*_weapon;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon &weapon);
		void	attack();
};