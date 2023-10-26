#include <string>
#include "Weapon.hpp"

class HumanA{
	private:
		Weapon &weapon;
		std::string Name;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void attack();
};