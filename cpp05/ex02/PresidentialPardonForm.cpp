#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), name("unknown"), sign(false), gradeToSign(25), gradeToExecute(5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm(), name(target), sign(false), gradeToSign(25), gradeToExecute(5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) { (void)other; }

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) { (void)other; return (*this); }

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::beSigned(const Bureaucrat& bro)
{
	if (this->sign == true)
		throw FormIsSigned();
	if (bro.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->sign = true;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->sign)
		throw FormIsntSigned();
	if (executor.getGrade() > this->gradeToExecute)
		throw GradeTooLowException();
	std::cout << this->name << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string			PresidentialPardonForm::getName() const { return (this->name); }
bool				PresidentialPardonForm::getSign() const { return (this->sign); }
int					PresidentialPardonForm::getGradeToSign() const { return (this->gradeToSign); }
int					PresidentialPardonForm::getGradeToExecute() const { return (this->gradeToExecute); }
