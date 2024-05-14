#include "PmergeMe.hpp"
#include <sys/time.h>

bool	isdigitStr(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

void	printUnsorted(char **argv)
{
	for (int i = 1; argv[i]; ++i)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Invalid arguement count" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe		algo;
		
		algo.parseInput(argv, argc);
		algo.sortAndPrint(argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}