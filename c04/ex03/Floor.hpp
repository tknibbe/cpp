#pragma once
#include "AMateria.hpp"

class AMateria;

class Floor {
	private:
		const AMateria	*_materia;
		Floor			*_next;
	protected:

	public:
		Floor(const AMateria *m);
		~Floor();
		Floor(const Floor& other);
		Floor&	operator=(const Floor& other);
		void	deleteNode(const AMateria* m); //gotta be made
		void	addNode(const AMateria* m);
		void	deleteWholeList(void);
};
