#include "easyfind.hpp"
#include <vector>

int main( void )
{
	std::vector<int> brat;

	for (int i = 0; i < 7; ++i)
		brat.push_back(i);
	try
	{
		std::vector<int>::iterator bro = easyfind(brat, 78798);
		std::cout << *bro << std::endl;
		std::cout << *brat.end() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	
}
