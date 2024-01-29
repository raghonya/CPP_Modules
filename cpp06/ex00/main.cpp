#include "ScalarConverter.hpp"
#include <cmath>
int	main(int argc, char** argv)
{
	// {
	// 	float b = strtod(argv[1], NULL);
	// 	std::cout << "PROBNIY MAIN\n" << std::endl;
	// 	std::cout << std::isinf(b) << std::endl;
	// 	// std::cout << "ERRNO: " << errno << std::endl;
	// 	std::cout << b << nullptr << std::endl;
	// 	std::cout << "\nPROBNIY MAIN\n" << std::endl;
	// }
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