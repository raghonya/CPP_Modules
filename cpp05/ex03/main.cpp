#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>

int	main()
{
	try
	{
		Intern	gagik;
		AForm*	newForm = gagik.makeForm("presidential", "home");
		Bureaucrat norik("norik", 111);

		norik.signForm(*newForm);

		std::cout << "form " << newForm->getName() << " " \
		<< newForm->getSign() << " " << newForm->getGradeToSign() \
		<< " " << newForm->getGradeToExecute() << std::endl;

		delete newForm;

	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	return (0);
}