#include "PmergeMe.hpp"
#include <sys/time.h>
#include <cstdlib>

void	print(std::vector<int> arr)
{
	for (std::vector<int>::iterator beg = arr.begin(); beg < arr.end(); ++beg )
		std::cout << *beg << std::endl;
}

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

	for (int i = 1; i < length; ++i)
	{
		if (!isdigitStr(input[i]))
			throw invalid_argument("Only digits");
		tmp = std::atoi(input[i]);
		if (tmp <= 0)
			throw invalid_argument("Only positive integers");
		vect.push_back(tmp);
		deq.push_back(tmp);
	}
}

void	PmergeMe::sortAndPrint(char **argv)
{
	struct timeval	time;

	std::cout << "Unsorted list: ";
	printUnsorted(argv);
	gettimeofday(&time, NULL);
	this->sortContainer(this->vect);
	this->printInfo(this->vect, time, "std::vector");
	gettimeofday(&time, NULL);
	this->sortContainer(this->deq);
	this->printInfo(this->deq, time, "std::deque");
}
