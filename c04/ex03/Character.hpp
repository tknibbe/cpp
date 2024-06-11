#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter{
	private:
		std::string	_name;
		AMateria 	*_inventory[4];
	protected:

	public:
		Character();
		Character(std::string name);
		virtual ~Character();
		Character(const Character& other);
		Character&	operator=(const Character& other);
		std::string const &	getName(void) const override;
		void	equip(AMateria *m) override;
		void	unequip(int idx) override;
		void	use(int idx, ICharacter& target) override;
};
