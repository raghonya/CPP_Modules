#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria's default constructor called" << std::endl;
	this->type = "undefined";
}

AMateria::AMateria(const AMateria& other)
{
	(void)other;
	std::cout << "AMateria's copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	(void)other;
	std::cout << "AMateria's assignment operator called" << std::endl;
	return (*this);
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria's parameter constructor called" << std::endl;
	this->type = type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "I'm a simple materia, i can't do something to " << target.getName() << ":(" << std::endl;
}

AMateria::~AMateria() { std::cout << "AMateria's destructor called" << std::endl; }
