#include <string>

class HumanB {
	private:
		Weapon &weapon;
		std::string	Name;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	attack();
};