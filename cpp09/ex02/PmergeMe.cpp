#include "PmergeMe.hpp"
#include <cstdlib>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	this->vect = other.vect;
	this->deq = other.deq;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	this->vect = other.vect;
	this->deq = other.deq;
	return (*this);
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::parseInput(char **input, int length)
{
	int		tmp;

	for (int i = 0; i < length; ++i)
	{
		if (!isdigitStr(input[i]))
			throw std::invalid_argument("Only digits");
		tmp = std::atoi(input[i]);
		if (tmp <= 0)
			throw std::invalid_argument("Only positive integers");
		vect.push_back(tmp);
		deq.push_back(tmp);
	}
}