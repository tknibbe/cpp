#pragma once
#include "IMateriaSource.hpp"
#include <array>
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource{
	private:
		AMateria	*_templates[4];
		int			_index;
	protected:

	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource&	operator=(const MateriaSource& other);
		void			learnMateria(AMateria *mat) override;
		AMateria		*createMateria(std::string const &type) override;
};
