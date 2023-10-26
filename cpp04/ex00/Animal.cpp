#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal's default constructor called" << std::endl;
	this->type = "Universal";	
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal's copy constructor called" << std::endl;
	this->type = other.type;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal's assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound() const { std::cout << "`Undefined sound`" << std::endl; }

Animal::~Animal() { std::cout << "Animal's destructor called" << std::endl; }
