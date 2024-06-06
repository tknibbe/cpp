#pragma once
#include "AMateria.hpp"


class Ice : public AMateria{
	private:

	protected:

	public:
		Ice();
		~Ice();
		Ice(const Ice& other);
		Ice&	operator=(const Ice& other);
		void 	use(ICharacter& target) override;
		virtual	Ice* clone() const override;
};
