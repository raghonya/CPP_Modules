#include <iostream>
#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc > 2 || (std::string(argv[1]).compare("DEBUG") \
	&& std::string(argv[1]).compare("WARNING") \
	&& std::string(argv[1]).compare("INFO") \
	&& std::string(argv[1]).compare("ERROR")))
	{
		std::cout << "Give one of these messages: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return (1);
	}
	Harl	a;

	a.setPtrs();
	a.complain(std::string(argv[1]));
	return (0);
}