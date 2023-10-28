#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure's default constructor called" << std::endl;
	this->type = "Cure";
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << "Cure's copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	std::cout << "Cure's assignment operator called" << std::endl;
}

AMateria*	Cure::clone() const
{
	AMateria	*newCure = new Cure();

	return (newCure);
}

Cure::~Cure() { std::cout << "Cure's destructor called" << std::endl; }
