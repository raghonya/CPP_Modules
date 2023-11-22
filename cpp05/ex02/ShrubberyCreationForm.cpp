#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), name("unknown"), gradeToSign(145), gradeToExecute(137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm(), name(target), gradeToSign(145), gradeToExecute(137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) { (void)other; }

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) { (void)other; return (*this); }

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->sign)
		throw FormIsntSigned();
	if (executor.getGrade() > this->gradeToExecute)
		throw GradeTooLowException();
	std::cout << "Creating ASCII tree..." << std::endl;
	/*
	
		zdes doljen bit kod ASCII tree
	
	*/
}
