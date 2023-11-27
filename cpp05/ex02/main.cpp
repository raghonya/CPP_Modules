#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>

int	main()
{
	try
	{
		ShrubberyCreationForm a("Formaeli");
		// std::cout << "demic  voreve bannnn " << a.getName() << " " << a.getSign() << std::endl;
		Bureaucrat bro("Hamlet", 2);
		bro.signForm(a);
		std::cout << "voreve bannnn " << a.getName() << " " << a.getSign() << std::endl;
		bro.executeForm(a);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	return (0);
}