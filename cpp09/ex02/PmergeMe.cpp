#include "PmergeMe.hpp"
#include <cstdlib>
#include <cmath>

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

void	intoPairs(vector &arr, vector &smalls)
{
	std::vector<int>	sortLarges;
	int					n = arr.size();

	for (int i = 0; i < n; i += 2)
	{
		if (i == n - 1)
			break ;
		std::cout << "arr[i] " << arr[i] << " arr[i + 1] " << arr[i + 1] << std::endl;
		if (arr[i] > arr[i + 1])
			std::swap(arr[i], arr[i + 1]);
		std::cout << "Erasing " << arr[i + 1] << std::endl;
		smalls.push_back(arr[i]);
		sortLarges.push_back(arr[i + 1]);
	}
	arr = sortLarges;

}

void	insert(vector &arr, vector smalls)
{
	vector	binarySearchArr;
	int		powerOf2 = 2;

	iterator it = smalls.begin();

	for (int i = 0; i < smalls.size(); ++i)
	{
		it += powerOf2;
		for (int j = 0; j < powerOf2 && j < smalls.size(); ++j)
		{
			binarySearchArr.push_back(*(it - j - 1));
		}
		powerOf2 = pow(2, i + 2) - powerOf2;
	}
	std::cout << "Printing binsrch arr" << std::endl;
	print(binarySearchArr);
}

void	notRealMerge(vector &arr)
{
	std::vector<int>	smalls;
	// bool	even = arr.size() % 2 == 0 ? true : false;

	if (arr.size() > 3)
	{
		intoPairs(arr, smalls);
		notRealMerge(arr);
		arr.insert(arr.begin(), smalls[0]);
		insert(arr, smalls);
	}
	else
	{
		if (arr[0] > arr[1])
			std::swap(arr[0], arr[1]);
		if (arr.size() == 3)
		{
			smalls.push_back(arr[2]);
			arr.erase(arr.end() - 1);
			insert(arr, smalls);
		}

	}

}

void	PmergeMe::sortVector()
{
	notRealMerge(this->vect);
	// slice(sortLarges, 0, sortLarges.size() - 1);
	std::cout << "vect====================" << std::endl;
	print(this->vect);
	std::cout << "vect end====================" << std::endl;
	// print(sortLarges);
}

