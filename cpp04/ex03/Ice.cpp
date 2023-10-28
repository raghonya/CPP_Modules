#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice's default constructor called" << std::endl;
	this->type = "ice";
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << "Ice's copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	std::cout << "Ice's assignment operator called" << std::endl;
}

AMateria*	Ice::clone() const
{
	AMateria	*newIce = new Ice();

	return (newIce);
}

Ice::~Ice() { std::cout << "Ice's destructor called" << std::endl; }
