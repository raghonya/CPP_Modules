#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private:
		std::vector<int>	arr;
		unsigned int		N;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
	public:
		void	addNumber(const int& num);
		int		longestSpan() const;
		int		shortestSpan() const;

		template <typename Iter> 
		void	addNumberIterator(Iter begin, Iter end);
};

template <typename Iter>
void	Span::addNumberIterator(Iter begin, Iter end)
{
	for (; begin < end; ++begin)
		addNumber(*begin);
}
#endif
