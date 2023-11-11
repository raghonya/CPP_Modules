#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	bro("Gag", 15);

		std::cout << bro << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	return (0);
}