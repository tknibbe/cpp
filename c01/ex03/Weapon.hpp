#include <string>

#pragma once

class Weapon {
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		~Weapon(void);
		std::string const &getType();
		void	setType(std::string weapon);
};