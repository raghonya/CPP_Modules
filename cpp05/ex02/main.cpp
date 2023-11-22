#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
// #include
#include <cstdlib>

int	main()
{
	try
	{
		ShrubberyCreationForm a;
		Bureaucrat b;
		AForm &c = a;
		b.signForm(c);


		// Form	*form = new ;
		// for (int i = 0; i < 10; i++)
		// std::cout << std::rand() % 2 << std::endl;
		
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	return (0);
}