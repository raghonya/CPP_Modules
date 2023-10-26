#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal's default constructor called" << std::endl;
	this->type = "Universal";	
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal's copy constructor called" << std::endl;
	this->type = other.type;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal's assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const { std::cout << "`Undefined sound`" << std::endl; }

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal's destructor called" << std::endl; }
