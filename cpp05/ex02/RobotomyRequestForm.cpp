#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : name("unknown"), gradeToSign(145), gradeToExecute(137) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : name(target), gradeToSign(145), gradeToExecute(137) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) { (void)other; }

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) { (void)other; return (*this); }

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::cout << "*some drilling noises*" << std::endl;
	stD::cout << "ban" << std::endl;
}
