#include "MateriaSource.hpp"

MateriaSource::MateriaSource() { std::cout << "MateriaSource's default constructor called" << std::endl; }

MateriaSource::MateriaSource(const MateriaSource& other)
{
	(void)other;
	std::cout << "MateriaSource's copy constructor called" << std::endl;
}

MateriaSource& operator=(const MateriaSource& other)
{
	(void)other;
	std::cout << "MateriaSource's assignment operator called" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource() { std::cout << "MateriaSource's default constructor called" << std::endl; }

