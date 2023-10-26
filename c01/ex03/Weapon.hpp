#include <string>

class Weapon {
	private:
		std::string type;
	public:
		Weapon(std::string type);
		~Weapon(void);
		std::string const &getType();
		void	setType(std::string weapon);
};