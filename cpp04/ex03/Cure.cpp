#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure's default constructor called" << std::endl;
	this->type = "Cure";
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	(void)other;
	std::cout << "Cure's copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	(void)other;
	std::cout << "Cure's assignment operator called" << std::endl;
	return (*this);
}

AMateria*	Cure::clone() const
{
	AMateria	*newCure = new Cure();

	return (newCure);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals "<< target.getName() << "’s wounds *" << std::endl;
}

Cure::~Cure() { std::cout << "Cure's destructor called" << std::endl; }
