#include "Span.hpp"

int main()
{
	{
		try
		{
			Span sp = Span(184);
			std::vector<int> arr;
			for (int i = 0; i < 155; ++i)
				arr.push_back(i);
			std::vector<int>::iterator beg = arr.begin();
			std::vector<int>::iterator end = arr.end();
			std::advance(beg, 14);
			sp.addNumberIterator(beg, end);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			std::cout << "First ended" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}