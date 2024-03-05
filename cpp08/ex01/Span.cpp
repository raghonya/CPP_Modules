#include "Span.hpp"
#include <cmath>
#include <climits>
#include <algorithm>

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span& other)
{
	this->N = other.N;
	this->arr = other.arr;
}

Span& Span::operator=(const Span& other)
{
	this->N = other.N;
	this->arr = other.arr;
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(const int& num)
{
	if (this->arr.size() == this->N)
		throw std::out_of_range("Not enough capacity");
	this->arr.push_back(num);
}

int	Span::longestSpan() const
{
	if (this->arr.size() <= 1)
		throw std::length_error("Cannot find a span");
	return (*std::max_element(arr.begin(), arr.end()) \
	- *std::min_element(arr.begin(), arr.end()));
}

int	Span::shortestSpan() const
{
	if (this->arr.size() <= 1)
		throw std::length_error("Cannot find a span");

	std::vector<int>	copy(arr);
	int					minSpan;

	std::sort(copy.begin(), copy.end());
	minSpan = copy[1] - copy[0];
	for (unsigned int i = 2; i < copy.size(); ++i)
		minSpan = (copy[i] - copy[i - 1] < minSpan ? \
		copy[i] - copy[i - 1] : minSpan);
	return (minSpan);
}
