#include "PmergeMe.hpp"
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

void	intoPairs(vector &arr, vector &sortLarges, vector &smalls)
{
	std::vector<int>	tmp;
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
		// arr.erase(arr.begin() + i + 1);
	}
	// print(arr);
	// print(sortLarges);

}

void	merge(vector &arr, int beg, int mid, int end)
{
	vector	right, left;

	for (int i = 0; i < mid - beg + 1; ++i)
		left.push_back(arr[beg + i]);
	for (int i = 0; i < end - mid; ++i)
		right.push_back(arr[mid + i + 1]);
	size_t i = 0, j = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j])
			arr[beg++] = left[i++];
		else
			arr[beg++] = right[j++];
	}
	while (i < left.size())
		arr[beg++] = left[i++];
	while (j < right.size())
		arr[beg++] = right[j++];
}

void	slice(vector &arr, int beg, int end)
{
	if (beg < end)
	{
		int	mid = (beg + end) / 2;
		slice(arr, beg, mid);
		slice(arr, mid + 1, end);
		merge(arr, beg, mid, end);
	}
}

void	PmergeMe::sortVector()
{
	std::vector<int> sortLarges, smalls;
	
	intoPairs(this->vect, sortLarges, smalls);
	slice(sortLarges, 0, sortLarges.size() - 1);
	std::cout << "vect====================" << std::endl;
	print(this->vect);
	std::cout << "vect end====================" << std::endl;
	
	sortLarges.insert(sortLarges.begin(), this->vect[0]);
	print(sortLarges);
}

