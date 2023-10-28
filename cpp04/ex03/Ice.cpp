#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice's default constructor called" << std::endl;
	this->type = "ice";
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	(void)other;
	std::cout << "Ice's copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	(void)other;
	std::cout << "Ice's assignment operator called" << std::endl;
	return (*this);
}

AMateria*	Ice::clone() const
{
	AMateria	*newIce = new Ice();

	return (newIce);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl;
}

Ice::~Ice() { std::cout << "Ice's destructor called" << std::endl; }