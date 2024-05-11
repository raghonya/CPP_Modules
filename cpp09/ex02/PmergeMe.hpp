#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

typedef std::invalid_argument		invalid_argument;
typedef std::vector<int>::iterator	iterator;
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
		void	parseInput(char **input, int length);
		void	sortVector();
};

bool	isdigitStr(const std::string &str);

#endif