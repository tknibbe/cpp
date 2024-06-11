#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void){
	// std::cout << "MateriaSource default constructor called" << std::endl;
	for(int i=0;i<4;i++)
		_templates[i] = nullptr;
	_index = 0;
}

MateriaSource::~MateriaSource(void){
	// std::cout << "MateriaSource destructor called" << std::endl;
	for(int i=0;i<4;i++)
	{
		delete _templates[i];
		_templates[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource& ref){
	std::cout << "MateriaSource copy constructor called" << std::endl;
	_index = ref._index;
	for (int i=0;i<4;i++)
	{
		if (ref._templates[i] != nullptr)
			this->_templates[i] = ref._templates[i]->clone();
		else
			this->_templates[i] = nullptr;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ref){
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		for (int i=0;i<4 && ref._templates[i] != nullptr;i++)
			this->_templates[i] = ref._templates[i]->clone();
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
			std::cout << "Material instance already in templates. doing nothing\n";
			return ;
		}
	}

	if (_index == 4)
		_index = 0;
	std::cout << "Learning Materia " << mat->getType() << " into slot " << _index << "\n";
	if (_templates[_index] != nullptr)
		delete _templates[_index];
	_templates[_index] = mat->clone();
	_index++;
}

AMateria	*MateriaSource::createMateria(std::string const &type){
	for (int i=0;i<4 && _templates[i] != nullptr;i++)
	{
		if (_templates[i]->getType() == type)
		{
			std::cout << "creating new materia " << _templates[i]->getType() <<  " from template\n";
			return (_templates[i]->clone());
		}
	}
	std::cout << "Error, template not found. returning nullptr\n";
	return nullptr;
}