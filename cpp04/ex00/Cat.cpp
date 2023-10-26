#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat's default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat's copy constructor called" << std::endl;
	this->type = other.type;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat's assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meowwwwwwww" << std::endl;
}

Cat::~Cat() { std::cout << "Cat's destructor called" << std::endl; }
