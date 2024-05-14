#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <sys/time.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

typedef std::invalid_argument		invalid_argument;
typedef std::vector<int>			vector;
typedef std::deque<int>				deque;

class PmergeMe
{
	private:
		std::vector<int>	vect;
		std::deque<int>		deq;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
	public:
		void	sortAndPrint(char **argv);
		void	parseInput(char **input, int length);
		template <typename C>
		void	printInfo(C cont, struct timeval time) const;
		template <typename C>
		void	sortContainer(C& cont);
};

bool	isdigitStr(const std::string &str);
void	printUnsorted(char **argv);

template <typename C>
void	intoPairs(C& arr, C& smalls)
{
	C			sortLarges;
	size_t		n = arr.size();

	for (size_t i = 0; i < n; i += 2)
	{
		if (i == n - 1)
		{
			smalls.push_back(arr[i]);
			break ;
		}
		if (arr[i] > arr[i + 1])
			std::swap(arr[i], arr[i + 1]);
		smalls.push_back(arr[i]);
		sortLarges.push_back(arr[i + 1]);
	}
	arr = sortLarges;

}

template <typename C>
void	insert(C &arr, C smalls)
{
	size_t	powerOf2 = 2;

	// std::cout << "SMALLS===========" << std::endl;
	// print(smalls);
	// std::cout << "Aand arr before" << std::endl;
	// print(arr);
	if (smalls.size() < 2)
	{
		arr.insert\
			(std::upper_bound(arr.begin(), arr.end(), *smalls.begin()), \
			*smalls.begin());
		return ;
	}
	for (size_t i = 0; !smalls.empty(); ++i)
	{
		typename C::iterator it = smalls.begin();
		it = it + (powerOf2 <= smalls.size() ? powerOf2 : smalls.size());
		for (size_t j = 0; j < powerOf2 && it - j - 1 >= smalls.begin(); ++j)
			arr.insert(std::upper_bound(arr.begin(), arr.end(), *(it - j - 1)), *(it - j - 1));
		for (size_t j = 0; j < powerOf2 && !smalls.empty(); ++j)
			smalls.erase(smalls.begin());
		powerOf2 = pow(2, i + 2) - powerOf2;
	}
	// std::cout <<"Arr after insert" <<std::endl;
	// print(arr);
}

template <typename C>
void	notRealMerge(C &arr)
{
	C	smalls;

	// std::cout << "larges array be like " << std::endl;
	// print(arr);
	if (arr.size() > 3)
	{
		intoPairs(arr, smalls);
		int minInd = 0;

		for (size_t i = 1; i < arr.size(); ++i)
			if (arr[minInd] > arr[i])
				minInd = i;
		notRealMerge(arr);
		arr.insert(arr.begin(), smalls[minInd]);
		smalls.erase(smalls.begin() + minInd);
		insert(arr, smalls);
	}
	else if (arr.size() > 1)
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

template <typename C>
void	PmergeMe::sortContainer(C& cont)
{
	notRealMerge(cont);
}

template <typename C>
void	PmergeMe::printInfo(C cont, struct timeval time) const
{
	double start = (double)time.tv_usec / 1000 + time.tv_sec * 1000;
	gettimeofday(&time, NULL);
	double	current = (double)time.tv_usec / 1000 + time.tv_sec * 1000;
	std::cout << "Sorted list: ";
	for (size_t i = 0; i < cont.size(); ++i)
		std::cout << cont[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << cont.size() << " elements with std::vector : ";
	std::cout << current - start  << " ms" << std::endl;
}

#endif
