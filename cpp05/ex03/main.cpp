#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	try
	{
		Intern	gagik;

		AForm*	newForm = gagik.makeForm("robotomy", "home");
		Bureaucrat norik("norik", 24);

		norik.signForm(*newForm);

		std::cout << *newForm << std::endl;

		delete newForm;

	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	return (0);
}