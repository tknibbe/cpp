#include "ICharacter.hpp"
#include <iostream>
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Floor.hpp"
#include "MateriaSource.hpp"

Floor *globalFloor = nullptr;

int main(void){

	// Character	oliver("Oliver");
	// Ice			*ice = new Ice();
	// Cure		*cure = new Cure();

	// oliver.equip(ice);
	// oliver.equip(cure);
	// oliver.unequip(1);
	// oliver.unequip(0);
	
	// Character tymon("tymon");
	// oliver.use(0, tymon);
	// oliver.use(1, tymon);
	// oliver.use(2, tymon);
	// oliver.use(3, tymon);
	// oliver.use(4, tymon);

	// Ice			*ice = new Ice();
	// Cure		*cure = new Cure();
	// Ice			*ice2 = new Ice();

	// oliver.equip(ice);
	// oliver.equip(ice);
	// oliver.equip(cure);
	// oliver.equip(ice2);
	// // oliver.unequip(0);
	// // oliver.unequip(2);
	// // oliver.unequip(1);
	// // oliver.equip(ice);
	// // oliver.equip(cure);
	// // oliver.equip(ice2);
	// oliver.unequip(0);
	// oliver.unequip(2);
	// oliver.unequip(1);
	// globalFloor->print();

	// globalFloor->deleteWholeList();

	IMateriaSource* src = new MateriaSource();
	AMateria	*test = new Ice();
	AMateria	*test1 = new Ice();
	AMateria	*test2 = new Ice();
	AMateria	*test3 = new Ice();
	src->learnMateria(test);
	src->learnMateria(test1);
	src->learnMateria(test2);
	src->learnMateria(test3);
	src->learnMateria(test);
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}