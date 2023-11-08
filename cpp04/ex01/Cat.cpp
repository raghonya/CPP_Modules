#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat's default constructor called" << std::endl;
	this->brain = new Brain();
	this->type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat's copy constructor called" << std::endl;

	this->type = other.type;

	this->brain = new Brain();
	for (int i = 0; i < 100; ++i)
		this->brain->setElement(other.brain->getElement(i), i);
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat's assignment operator called" << std::endl;

	if (this == &other)
		return (*this);

	this->type = other.type;

	delete this->brain;
	this->brain = new Brain();
	for (int i = 0; i < 100; ++i)
		this->brain->setElement(other.brain->getElement(i), i);

	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meowwwwwwww" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat's destructor called" << std::endl;
	delete this->brain;
}
