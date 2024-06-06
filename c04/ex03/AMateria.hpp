#pragma once

#include "ICharacter.hpp"
#include "Floor.hpp"
#include <iostream>

class ICharacter;
class Floor;
extern Floor *globalFloor;

class AMateria {
	private:

	protected:
		std::string _type;
		
	public:
		AMateria(std::string const &type);
		virtual ~AMateria();
		AMateria(const AMateria& other);
		AMateria&	operator=(const AMateria& other);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
