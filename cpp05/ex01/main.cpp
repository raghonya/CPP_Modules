#include "Form.hpp"

int	main()
{
	try
	{
		// Bureaucrat	bro("Gag", 15);

		// std::cout << bro << std::endl;
		Form	dprocicDusMnaluForm("Hamletik", 15, 25);

		std::cout << dprocicDusMnaluForm << std::endl;

		Bureaucrat boz("a", 2);
		// dprocicDusMnaluForm.beSigned(boz);
		boz.signForm(dprocicDusMnaluForm);
		std::cout << dprocicDusMnaluForm.getSign() << std::endl;;
		boz.signForm(dprocicDusMnaluForm);
		// dprocicDusMnaluForm.beSigned(boz);
		
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	return (0);
}