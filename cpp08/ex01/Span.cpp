#include "Span.hpp"
#include <cmath>
#include <climits>

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span& other)
{
	this->arr = other.arr;
	this->N = other.N;
}

Span& Span::operator=(const Span& other)
{
	if (this->arr == other.arr)
		return (*this);
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
	if (this->N <= 1)
		throw std::length_error("Cannot find a span");

	int	maxSpan = 0;
	for (unsigned int i = 0; i < arr.size(); ++i)
		for (unsigned int j = i + 1; j < arr.size(); ++j)
			if (abs(arr[i] - arr[j]) > maxSpan)
				maxSpan = abs(arr[i] - arr[j]);
	return (maxSpan);
}

int	Span::shortestSpan() const
{
	if (this->N <= 1)
		throw std::length_error("Cannot find a span");

	int	minSpan = INT_MAX;
	for (unsigned int i = 0; i < arr.size(); ++i)
		for (unsigned int j = i + 1; j < arr.size(); ++j)
			if (abs(arr[i] - arr[j]) < minSpan)
				minSpan = abs(arr[i] - arr[j]);
	return (minSpan);
}
