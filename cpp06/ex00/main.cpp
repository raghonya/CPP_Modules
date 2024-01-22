#include "ScalarConverter.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage of program: ./converter `number`" << std::endl;
		return (1);
	}
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}