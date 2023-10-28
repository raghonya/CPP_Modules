#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout << "ICharacter's default constructor called" << std::endl;
	this->type = "undefined";
}

ICharacter::ICharacter(const ICharacter& other)
{
	(void)other;
	std::cout << "ICharacter's copy constructor called" << std::endl;
}

ICharacter& ICharacter::operator=(const ICharacter& other)
{
	(void)other;
	std::cout << "ICharacter's assignment operator called" << std::endl;
}

std::string const & ICharacter::getName() const
{
	return (this->name);
}
