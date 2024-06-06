#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void){
	std::cout << "MateriaSource default constructor called" << std::endl;
	for(int i=0;i<4;i++)
		_templates[i] = nullptr;
}

MateriaSource::~MateriaSource(void){
	std::cout << "MateriaSource destructor called" << std::endl;
	for(int i=0;i<4;i++)
	{
		delete _templates[i];
		_templates[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource& ref){
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = ref;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ref){
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		/*
		specify instructions here
		*/
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *mat){

	if (mat == nullptr)
	{
		std::cout << "Materia doesn't exist. nothing to learn\n";
		return ;
	}

	for (int i=0;i<4;i++)
	{
		if (mat == _templates[i])
		{
			std::cout << "Material instance already in template. doing nothing\n";
			return ;
		}
	}

	std::cout << "Learning Materia\n";
	static int i;

	std::cout << "I = " << i << "\n";
	if (i == 4)
		i = 0;
	if (_templates[i] != nullptr)
		delete _templates[i];
	_templates[i] = mat;
	i++;
}

AMateria	*MateriaSource::createMateria(std::string const &type){
	for (int i=0;i<4;i++)
	{
		if (_templates[i]->getType() == type)
		{
			std::cout << "creating new materia from template\n";
			return (_templates[i]->clone());
		}
	}
	std::cout << "Error, template not found. returning nullptr\n";
	return nullptr;
}