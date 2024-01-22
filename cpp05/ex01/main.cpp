#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat barev("yani", 4);
		Form	form("anun", 111, 777);
		
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	return (0);
}