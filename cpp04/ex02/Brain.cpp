#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain's default constructor called" << std::endl; }

Brain::Brain(const Brain& other)
{
	std::cout << "Brain's copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Brain's assignment operator called" << std::endl;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

std::string	Brain::getElement(int index) const
{
	return (*(this->ideas + index));
}

void	Brain::setElement(std::string idea, int index)
{
	this->ideas[index] = idea;
}

Brain::~Brain() { std::cout << "Brain's destructor called" << std::endl; }
