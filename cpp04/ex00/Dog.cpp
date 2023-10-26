#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog's default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog's copy constructor called" << std::endl;
	this->type = other.type;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog's assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof" << std::endl;
}

Dog::~Dog() { std::cout << "Dog's destructor called" << std::endl; }
