#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), name("unknown"), gradeToSign(25), gradeToExecute(5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm(), name(target), gradeToSign(25), gradeToExecute(5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) { (void)other; }

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) { (void)other; return (*this); }

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->sign)
		throw FormIsntSigned();
	if (executor.getGrade() > this->gradeToExecute)
		throw GradeTooLowException();
	std::cout << this->name << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
