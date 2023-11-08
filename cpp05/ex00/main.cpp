#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	bro("Gag", 155);
	}
	catch (const std::exception& e)
	{
		// std::cout << "Exception catched" << std::endl;
		std::cerr << e.what() << std::endl;;
	}
	return (0);
}