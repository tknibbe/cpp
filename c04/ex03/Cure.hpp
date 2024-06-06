#pragma once
#include "AMateria.hpp"


class Cure : public AMateria{
	private:

	protected:

	public:
		Cure();
		~Cure();
		Cure(const Cure& other);
		Cure&	operator=(const Cure& other);
		void 	use(ICharacter& target) override;
		virtual	Cure* clone() const override;
};
