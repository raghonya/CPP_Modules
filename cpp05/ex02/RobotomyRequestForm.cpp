#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(), name("unknown"), sign(false), gradeToSign(72), gradeToExecute(45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm(), name(target), sign(false), gradeToSign(72), gradeToExecute(45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) { (void)other; }

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) { (void)other; return (*this); }

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::beSigned(const Bureaucrat& bro)
{
	if (this->sign == true)
		throw FormIsSigned();
	if (bro.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->sign = true;
}

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

std::string			RobotomyRequestForm::getName() const { return (this->name); }
bool				RobotomyRequestForm::getSign() const { return (this->sign); }
int					RobotomyRequestForm::getGradeToSign() const { return (this->gradeToSign); }
int					RobotomyRequestForm::getGradeToExecute() const { return (this->gradeToExecute); }
