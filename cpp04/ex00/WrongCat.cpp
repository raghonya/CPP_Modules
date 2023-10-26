#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat's default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat's copy constructor called" << std::endl;
	this->type = other.type;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat's assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meowwwwwwww" << std::endl;
}

WrongCat::~WrongCat() { std::cout << "WrongCat's destructor called" << std::endl; }
