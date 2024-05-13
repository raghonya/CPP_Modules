#include "PmergeMe.hpp"
#include <sys/time.h>
#include <algorithm>
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

void	PmergeMe::printInfo(struct timeval time) const
{
	time_t start = 
			(time.tv_sec) * 1000 + (time.tv_usec) / 1000;
	
	gettimeofday(&time, NULL);
	time_t	current = 
			(time.tv_sec) * 1000 + (time.tv_usec) / 1000;
	
	std::cout << "cur start: " << current << " " << start << std::endl;
	std::cout << "Sorted list: ";
	for (int i = 0; i < this->vect.size(); ++i)
		std::cout << this->vect[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << this->vect.size() << " elements with std::vector : ";
	std::cout << current - start << std::endl;
}

void	intoPairs(vector &arr, vector &smalls)
{
	std::vector<int>	sortLarges;
	int					n = arr.size();

	for (int i = 0; i < n; i += 2)
	{
		if (i == n - 1)
		{
			smalls.push_back(arr[i]);
			break ;
		}
		// std::cout << "arr[i] " << arr[i] << " arr[i + 1] " << arr[i + 1] << std::endl;
		if (arr[i] > arr[i + 1])
			std::swap(arr[i], arr[i + 1]);
		smalls.push_back(arr[i]);
		sortLarges.push_back(arr[i + 1]);
	}
	arr = sortLarges;

}

void	insert(vector &arr, vector smalls)
{
	vector	binarySearchArr;
	size_t	powerOf2 = 2;

	// std::cout << "SMALLS===========" << std::endl;
	// print(smalls);
	if (smalls.size() < 2)
	{
		arr.insert\
			(std::upper_bound(arr.begin(), arr.end(), *smalls.begin()), \
			*smalls.begin());
		return ;
	}
	for (size_t i = 0; i < smalls.size(); ++i)
	{
		iteratorV it = smalls.begin();
		it += powerOf2;
		for (size_t j = 0; j < powerOf2 && j < smalls.size(); ++j)
			arr.insert(std::upper_bound(arr.begin(), arr.end(), *(it - j - 1)), *(it - j - 1));
		// for (size_t j = 0; j < smalls.size(); ++j)
		for (size_t j = 0; j < powerOf2; ++j)
			smalls.erase(it - j - 1);
		powerOf2 = pow(2, i + 2) - powerOf2;
	}
	// std::cout << "Printing binsrch arr" << std::endl;
	// print(binarySearchArr);
}

void	notRealMerge(vector &arr)
{
	std::vector<int>	smalls;

	// std::cout << "larges array be like " << std::endl;
	// print(arr);
	if (arr.size() > 3)
	{
		intoPairs(arr, smalls);
		// std::cout << "LANVEEEENNN\n";
		// print(arr);
		// print(smalls);
		int minInd = 0;

		for (int i = 1; i < arr.size(); ++i)
			if (arr[minInd] > arr[i])
				minInd = i;
		notRealMerge(arr);
		arr.insert(arr.begin(), smalls[minInd]);
		// std::cout << "Gnuma inset" << std::endl;
		// print(arr);
		insert(arr, smalls);
	}
	else if (arr.size() > 1)
	{
		if (arr[0] > arr[1])
			std::swap(arr[0], arr[1]);
		// std::cout << "LARGES WHEN SIZE < 3" << std::endl;
		// print(arr);
		if (arr.size() == 3)
		{
			smalls.push_back(arr[2]);
			arr.erase(arr.end() - 1);
			// std::cout << "BLYAAAAAA\n";
			// print(arr);
			// std::cout << "BLYAAAAAA123213\n";
			// print(smalls);
			insert(arr, smalls);
		}
	}

}

void	PmergeMe::sortVector()
{
	notRealMerge(this->vect);
	// slice(sortLarges, 0, sortLarges.size() - 1);
	// std::cout << "vect====================" << std::endl;
	// print(this->vect);
	// std::cout << "vect end====================" << std::endl;
	// print(sortLarges);
}

