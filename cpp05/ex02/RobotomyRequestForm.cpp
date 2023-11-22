#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(), name("unknown"), gradeToSign(72), gradeToExecute(45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm(), name(target), gradeToSign(72), gradeToExecute(45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) { (void)other; }

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) { (void)other; return (*this); }

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->sign)
		throw FormIsntSigned();
	if (executor.getGrade() > this->gradeToExecute)
		throw GradeTooLowException();
	std::cout << "*some drilling noises*" << std::endl;
	if (std::rand() % 2)
		std::cout << this->name << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed!!!" << std::endl;

}
