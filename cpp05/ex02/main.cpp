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
		Bureaucrat bro("Hamlet", 50);
		bro.signForm(a);
		std::cout << "Shrubberry form: " << a.name << " " << a.gradeToSign << " " << a.gradeToExecute << " " << a.sign << std::endl;
		bro.executeForm(a);

		RobotomyRequestForm	b("RoboForm");
		bro.signForm(b);
		std::cout << "Robotomy form: " << b.getName() << " " << b.getGradeToSign() << " " << b.getGradeToExecute() << " " << b.getSign() << std::endl;
		bro.executeForm(b);
		
		PresidentialPardonForm	c("PresidentalForm");
		bro.signForm(c);
		std::cout << "Presidential form: " << c.getName() << " " << c.getGradeToSign() << " " << c.getGradeToExecute() << " " << c.getSign() << std::endl;
		bro.executeForm(c);
		std::cout << c << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	return (0);
}