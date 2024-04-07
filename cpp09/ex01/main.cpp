#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: " << "./RPN \"operation\"" << std::endl;
		return (1);
	}

	try
	{
		RPN		*calculator = new RPN();

		try
		{
			calculator->parse((std::string)argv[1]);
			std::cout << calculator->operation((std::string)argv[1]) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		delete calculator;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}