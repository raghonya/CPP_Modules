#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout << "ICharacter's default constructor called" << std::endl;
}

ICharacter::ICharacter(std::string name)
{
	std::cout << "ICharacter's parameter constructor called" << std::endl;
	this->name = name;
}

ICharacter::ICharacter(const ICharacter& other)
{
	std::cout << "ICharacter's copy constructor called" << std::endl;
	this->name = other.name;
}

ICharacter& ICharacter::operator=(const ICharacter& other)
{
	std::cout << "ICharacter's assignment operator called" << std::endl;
	this->name = name;
	for (int i = 0; i < 4, i++)
		delete	inventory[i];
	delete[] inventory;
	inventory = new AMateria*[4];
	for (int i = 0; i < 4, i++)
	{
		;
	}
	return (*this);
}

std::string const & ICharacter::getName() const
{
	return (this->name);
}
