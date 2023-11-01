#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
	// std::cout << "MateriaSource's default constructor called" << std::endl;
	inventory = new AMateria*[4];
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	// std::cout << "MateriaSource's copy constructor called" << std::endl;
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = other.inventory[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	// std::cout << "MateriaSource's assignment operator called" << std::endl;

	if (this == &other)
		return (*this);

	for (int i = 0; i < 4; ++i)
		delete this->inventory[i];
	delete[] this->inventory;
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = other.inventory[i];

	return (*this);
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource's destructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		delete this->inventory[i];
	delete[] this->inventory;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	int	i = 0;

	while (i < 4 && this->inventory[i])
		i++;
	if (i < 4)
	{
		if (m->getType().compare("ice"))
			this->inventory[i] = new Ice;
		else if (m->getType().compare("cure"))
			this->inventory[i] = new Cure;
	}
	else
		std::cout << "Not enough space to learn materia" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	int	i = 0;

	while (i < 4 && this->inventory[i])
	{
		if (!this->inventory[i]->getType().compare(type))
		{
			if (type.compare("ice"))
				return (new Ice);
			else if (type.compare("cure"))
				return (new Cure);
		}
		i++;
	}
	return (nullptr);
}