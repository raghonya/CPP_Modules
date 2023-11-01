#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
	// std::cout << "AMateria's default constructor called" << std::endl;
	this->type = "undefined";
}

AMateria::AMateria(std::string const & type)
{
	// std::cout << "AMateria's parameter constructor called" << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria& other)
{
	// std::cout << "AMateria's copy constructor called" << std::endl;
	this->type = other.type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	// std::cout << "AMateria's assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "I'm a simple materia, i can't do something to " << target.getName() << ":(" << std::endl;
}

AMateria::~AMateria() { /*std::cout << "AMateria's destructor called" << std::endl;*/ }
