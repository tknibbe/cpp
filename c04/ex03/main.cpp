#include "ICharacter.hpp"
#include <iostream>
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Floor.hpp"
#include "MateriaSource.hpp"

Floor *globalFloor = nullptr;

int main(void){

	// basic tests
	IMateriaSource* src = new MateriaSource();
	Ice				*icy = new Ice();//
	Cure			*cury = new Cure();//
	src->learnMateria(icy);//
	src->learnMateria(cury);//
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;//
	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp; //
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	delete icy;
	delete cury;




	// // make sure leaks are avoided when characters with materia get reassigned
	// Character	leakCheck1 = Character("leak1");
	// Character	leakCheck2 = Character("leak2");
	// Ice			*leak1 = new Ice();
	// Cure		*leak2 = new Cure();

	// leakCheck1.equip(leak1);
	// leakCheck2.equip(leak2);

	// leakCheck2 = leakCheck1;

	// leakCheck2.use(0, leakCheck2);
	// // delete	leakCheck1;
	// delete leak1;
	// delete leak2;



	// // equip/unequipping tests
	// Character	oliver("Oliver");
	// Ice			*oliverIce = new Ice();
	// Cure		*oliverCure = new Cure();

	// oliver.equip(oliverIce);
	// oliver.equip(oliverCure);
	// oliver.unequip(1);
	// oliver.unequip(0);

	// delete oliverCure;
	// delete oliverIce;
	
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
	// oliver.unequip(0);
	// oliver.unequip(2);
	// oliver.unequip(1);
	// oliver.equip(ice);
	// oliver.equip(cure);
	// oliver.equip(ice2);
	// oliver.unequip(0);
	// oliver.unequip(2);
	// oliver.unequip(1);

	// delete ice;
	// delete cure;
	// delete ice2;

	
	globalFloor->deleteWholeList();
	return 0;
}